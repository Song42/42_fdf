/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:09:46 by schaehun          #+#    #+#             */
/*   Updated: 2022/05/24 16:17:01 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
	{
		write(1, "usage: ./fdf [filename]\n", 24);
		return (RUN_COMMAND_ERROR);
	}
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "42 FDF");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	read_map(&data, argv[1]);
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_hook(data.win_ptr, 17, 1L << 17, close_all, &data);
	mlx_hook(data.win_ptr, 2, 1L << 0, key_press, &data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_loop(data.mlx_ptr);
}
