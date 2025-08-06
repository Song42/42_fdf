/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:55:02 by schaehun          #+#    #+#             */
/*   Updated: 2022/06/07 18:51:24 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	add_line(t_data *data, char **data_z)
{
	int	i;

	i = -1;
	if (data->map.z == NULL)
	{
		data->map.z = malloc(sizeof(int *) * 1);
		data->map.z[0] = malloc(sizeof(int) * data->map.x);
		while (data_z[++i])
			data->map.z[0][i] = ft_atoi(data_z[i]);
	}
	else
	{
		copy_arr(data, data_z);
	}
}

void	set_line_vars(t_line *line)
{
	line->deltax = abs(line->x1 - line->x0);
	line->deltay = abs(line->y1 - line->y0);
	line->error = 0;
	line->deltaerr = line->deltay + 1;
	line->y = line->y0;
	line->diry = line->y1 - line->y0;
	if (line->diry > 0)
		line->diry = 1;
	if (line->diry < 0)
		line->diry = -1;
	if (line->x0 <= line->x1)
		line->x = line->x0;
	if (line->x0 > line->x1)
	{
		line->x = line->x1;
		line->x1 = line->x0;
	}
}

void	make_line(t_data *data, t_line *line)
{
	set_line_vars(line);
	while (line->x <= line->x1 + 1)
	{
		if (line->x < WINDOW_WIDTH && line->y < WINDOW_HEIGHT
			&& line->x > 0 && line->y > 0)
			img_pixel_put(data, line->x, line->y, 0xFF483F);
		if (line->error >= (line->deltax + 1))
		{
			line->y = line->y + line->diry;
			line->error = line->error - (line->deltax + 1);
			continue ;
		}
		line->error = line->error + line->deltaerr;
		line->x++;
	}
}

void	set_line_pos(t_data *data, t_line *line, int j, int i)
{
	double	degree;

	degree = 0.523599;
	if (line->flag == 0)
	{
		line->x0 = WINDOW_WIDTH / 2 + data->map.scale * ((j - i)
				* cos(degree) + data->map.pos_x);
		line->y0 = WINDOW_HEIGHT / 2 + data->map.scale * (data->map.z[i][j]
				* -1 + (j + i) * sin(degree) + data->map.pos_y);
		line->x1 = WINDOW_WIDTH / 2 + data->map.scale * ((j + 1 - i)
				* cos(degree) + data->map.pos_x);
		line->y1 = WINDOW_HEIGHT / 2 + data->map.scale * (data->map.z[i][j + 1]
				* -1 + (j + 1 + i) * sin(degree) + data->map.pos_y);
	}
	if (line->flag == 1)
	{
		line->x0 = WINDOW_WIDTH / 2 + data->map.scale * ((j - i)
				* cos(degree) + data->map.pos_x);
		line->y0 = WINDOW_HEIGHT / 2 + data->map.scale * (data->map.z[i][j]
				* -1 + (j + i) * sin(degree) + data->map.pos_y);
		line->x1 = WINDOW_WIDTH / 2 + data->map.scale * ((j + 1 - i)
				* cos(degree) + data->map.pos_x);
		line->y1 = WINDOW_HEIGHT / 2 + data->map.scale * (data->map.z[i - 1][j]
				* -1 + (j - 1 + i) * sin(degree) + data->map.pos_y);
	}
}

void	draw_line(t_data *data, int j, int i)
{
	t_line	line;

	if (j != data->map.x - 1)
	{
		line.flag = 0;
		set_line_pos(data, &line, j, i);
		make_line(data, &line);
	}
	if (i != 0)
	{
		line.flag = 1;
		set_line_pos(data, &line, j, i);
		make_line(data, &line);
	}
}
