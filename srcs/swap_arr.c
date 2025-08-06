/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:56:41 by schaehun          #+#    #+#             */
/*   Updated: 2022/05/24 16:08:51 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	paste_arr(t_data *data, int **temp_arr, char **data_z)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.y)
	{
		j = -1;
		while (++j < data->map.x)
			data->map.z[i][j] = temp_arr[i][j];
	}
	j = -1;
	while (++j < data->map.x)
		data->map.z[i][j] = ft_atoi(data_z[j]);
}

void	copy_arr(t_data *data, char **data_z)
{
	int	i;
	int	j;
	int	**temp_arr;

	temp_arr = malloc(sizeof(int *) * data->map.y);
	i = -1;
	while (++i < data->map.y)
		temp_arr[i] = malloc(sizeof(int) * data->map.x);
	i = -1;
	while (++i < data->map.y)
	{
		j = -1;
		while (++j < data->map.x)
			temp_arr[i][j] = data->map.z[i][j];
	}
	re_malloc(data);
	paste_arr(data, temp_arr, data_z);
	i = -1;
	while (++i < data->map.y)
		free(temp_arr[i]);
	free(temp_arr);
}
