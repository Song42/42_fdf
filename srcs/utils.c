/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:51:37 by schaehun          #+#    #+#             */
/*   Updated: 2022/07/17 02:31:19 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	img_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(int *) pixel = color;
}

int	render(t_data *data)
{
	render_bg(data);
	render_map(data);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

void	re_malloc(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->map.y)
		free(data->map.z[i]);
	free(data->map.z);
	data->map.z = malloc(sizeof(int *) * (data->map.y + 1));
	i = 0;
	while (i < data->map.y + 1)
	{
		data->map.z[i] = malloc(sizeof(int) * data->map.x);
		i++;
	}
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_all(data, USER_EXIT);
	if (keycode == 45 && data->map.scale > 0)
		data->map.scale--;
	if (keycode == 61)
		data->map.scale++;
	if (keycode == 119)
		data->map.pos_y--;
	if (keycode == 97)
		data->map.pos_x--;
	if (keycode == 115)
		data->map.pos_y++;
	if (keycode == 100)
		data->map.pos_x++;
	if (keycode == 32)
	{
		data->map.pos_x = 0;
		data->map.pos_y = 0;
		data->map.scale = 10;
	}
	return (0);
}

int	close_all(t_data *data, int error)
{
	int	i;

	i = -1;
	while (++i < data->map.y)
		free(data->map.z[i]);
	free(data->map.z);
	if (error != 3 && error != 4)
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	if (error == 3)
		write(2, "couldn't access file\n", 21);
	if (error == 4)
	{
		write(2, "empty map\n", 10);
		close(data->map.fd);
	}
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(error);
}
