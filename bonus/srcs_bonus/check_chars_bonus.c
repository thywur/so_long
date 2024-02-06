/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:06:59 by alermolo          #+#    #+#             */
/*   Updated: 2024/02/06 14:39:03 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	count_e(t_data *data)
{
	int	i;
	int	j;
	int	e_count;

	i = 0;
	e_count = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
				e_count++;
			j++;
		}
		i++;
	}
	if (e_count != 1)
		err_msg(data, "Map must have exactly one exit");
	return (e_count);
}

static int	count_c(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->c_count = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->c_count++;
			j++;
		}
		i++;
	}
	if (data->c_count < 1)
		err_msg(data, "Map must have at least one collectible");
	return (data->c_count);
}

static int	count_p(t_data *data)
{
	int	i;
	int	j;
	int	p_count;

	i = 0;
	p_count = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				p_count++;
			j++;
		}
		i++;
	}
	if (p_count != 1)
		err_msg(data, "Map must have exactly one player");
	return (p_count);
}

static void	set_coords(t_coords *coords, int i, int j)
{
	coords->x = j * SIZE;
	coords->y = i * SIZE;
}

int	chars_valid(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (!ft_strchr("01CEP", data->map[i][j]))
				err_msg(data, "Invalid character in map");
				// return (0);
			if (data->map[i][j] == 'P')
				set_coords(&data->player, i, j);
			if (data->map[i][j] == 'E')
				set_coords(&data->exit, i, j);
			j++;
		}
		i++;
	}
	if (count_p(data) != 1 || count_e(data) != 1 || count_c(data) < 1)
		return (0);
	return (1);
}
