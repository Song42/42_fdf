/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:04:27 by schaehun          #+#    #+#             */
/*   Updated: 2022/07/17 02:45:42 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>

# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# define USER_EXIT 0
# define MLX_ERROR 1
# define RUN_COMMAND_ERROR 2
# define FILE_ERROR 3
# define MAP_ERROR 4

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_map
{
	int		x;
	int		y;
	int		**z;
	int		pos_x;
	int		pos_y;
	int		scale;
	int		fd;
	double	degree;
	char	*file;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	map;
}	t_data;

typedef struct s_line
{
	int	deltax;
	int	deltay;
	int	error;
	int	deltaerr;
	int	x;
	int	y;
	int	diry;
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	flag;
}	t_line;

int		close_all(t_data *data, int error);
void	img_pixel_put(t_data *data, int x, int y, int color);
void	re_malloc(t_data *data);
void	paste_arr(t_data *data, int **temp_arr, char **data_z);
void	copy_arr(t_data *data, char **data_z);
void	add_line(t_data *data, char **data_z);
void	set_map_vars(t_data *data, char *filename);
void	read_map(t_data *data, char *filename);
void	render_bg(t_data *data);
void	set_line_vars(t_line *line);
void	make_line(t_data *data, t_line *line);
void	set_line_pos(t_data *data, t_line *line, int j, int i);
void	draw_line(t_data *data, int j, int i);
void	render_map(t_data *data);
int		render(t_data *data);
int		key_press(int keycode, t_data *data);

#endif
