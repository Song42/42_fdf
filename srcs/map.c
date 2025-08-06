/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:56:03 by schaehun          #+#    #+#             */
/*   Updated: 2022/07/17 02:31:58 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_map_vars(t_data *data, char *filename)
{
	data->map.x = 0;
	data->map.y = 0;
	data->map.pos_x = 0;
	data->map.pos_y = 0;
	data->map.z = NULL;
	data->map.scale = 10;
	data->map.file = filename;
	data->map.fd = open(data->map.file, O_RDONLY);
	if (data->map.fd < 0 || ft_strnstr(filename, ".fdf",
			ft_strlen(filename)) == NULL)
	{
		close(data->map.fd);
		close_all(data, FILE_ERROR);
	}
}

void	read_map(t_data *data, char *filename)
{
	int		i;
	char	**data_z;
	char	*line;

	set_map_vars(data, filename);
	line = get_next_line(data->map.fd);
	if (line == NULL)
		close_all(data, MAP_ERROR);
	data_z = ft_split(line, ' ');
	free(line);
	while (data_z[data->map.x])
		data->map.x++;
	while (data_z != NULL)
	{
		add_line(data, data_z);
		line = get_next_line(data->map.fd);
		i = -1;
		while (data_z[++i])
			free(data_z[i]);
		free(data_z);
		data_z = ft_split(line, ' ');
		free(line);
		data->map.y++;
	}
	close(data->map.fd);
}

void	render_bg(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGHT)
		{
			img_pixel_put(data, i, j, 0x2E3047);
			j++;
		}
		i++;
	}
}

void	render_map(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->map.y)
	{
		j = 0;
		while (j < data->map.x)
		{
			draw_line(data, j, i);
			j++;
		}
		i++;
	}
}
