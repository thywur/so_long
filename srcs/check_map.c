/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:37:21 by alermolo          #+#    #+#             */
/*   Updated: 2024/02/06 14:07:16 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_rectangular(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if ((int)ft_strlen(data->map[i]) != data->map_w / SIZE)
			return (0);
		i++;
	}
	return (1);
}

int	walls_ok(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[0][j])
	{
		if (data->map[0][j] != '1' ||
			data->map[data->map_h / SIZE - 1][j] != '1')
			return (0);
		j++;
	}
	while (data->map[i])
	{
		if (data->map[i][0] != '1' ||
			data->map[i][data->map_w / SIZE - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	check_access(t_data *data, int i, int j)
{
	if (data->map_check[i][j - 1] != '1')
	{
		data->map_check[i][j - 1] = '1';
		check_access(data, i, j - 1);
	}
	if (data->map_check[i][j + 1] != '1')
	{
		data->map_check[i][j + 1] = '1';
		check_access(data, i, j + 1);
	}
	if (data->map_check[i - 1][j] != '1')
	{
		data->map_check[i - 1][j] = '1';
		check_access(data, i - 1, j);
	}
	if (data->map_check[i + 1][j] != '1')
	{
		data->map_check[i + 1][j] = '1';
		check_access(data, i + 1, j);
	}
	data->map_check[i][j] = '1';
}

int	is_solvable(t_data *data)
{
	int	i;
	int	j;

	check_access(data, data->player.y / SIZE, data->player.x / SIZE);
	i = 0;
	while (data->map_check[i])
	{
		j = 0;
		while (data->map_check[i][j])
		{
			if (data->map_check[i][j] == 'E' || data->map_check[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	map_valid(t_data *data)
{
	if (!map_rectangular(data))
		err_msg(data, "Map is not rectangular");
		// return (0);
	if (!walls_ok(data))
		err_msg(data, "Map is not surrounded by walls");
		// return (0);
	if (!chars_valid(data))
		err_msg(data, "Invalid characters in map");
		// return (0);
	if (!is_solvable(data))
		err_msg(data, "Map is not solvable");
		// return (0);
	return (1);
}
