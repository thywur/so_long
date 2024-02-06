/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:55:45 by alermolo          #+#    #+#             */
/*   Updated: 2024/02/02 13:50:16 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_sprite(t_data *data, int x, int y, char c)
{
	if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.empty.addr, x, y);
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.wall.addr, x, y);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.item.addr, x, y);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.exit.addr, x, y);
	if (c == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player_d2.addr, x, y);
		data->player.x = x;
		data->player.y = y;
		data->map[y / SIZE][x / SIZE] = 'P';
		mlx_string_put(data->mlx, data->win, 5, 15, 0x00FFFFFF, "Moves: ");
		mlx_string_put(data->mlx, data->win, 60, 15, 0x00FFFFFF, "0");
	}
}

void	fill_top_wall(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->map_w)
	{
		put_sprite(data, x, y, '1');
		x += SIZE;
	}
}

void	fill_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_h)
	{
		x = 0;
		while (x < data->map_w)
		{
			put_sprite(data, x, y, '0');
			x += SIZE;
		}
		y += SIZE;
	}
}

void	print_map(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	if (!map_valid(data))
		err_msg(data, "Map error");
	fill_map(data);
	while (data->map[i])
	{
		j = 0;
		x = 0;
		while (data->map[i][j])
		{
			put_sprite(data, x, y, data->map[i][j]);
			if (data->map[i][j] == '0')
				data->has_empty = 1;
			x += SIZE;
			j++;
		}
		y += SIZE;
		i++;
	}
}
