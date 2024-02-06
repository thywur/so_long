/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:55:45 by alermolo          #+#    #+#             */
/*   Updated: 2024/01/31 16:50:46 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			data->img.player.addr, x, y);
		data->player.x = x;
		data->player.y = y;
		data->map[y / SIZE][x / SIZE] = '0';
		ft_printf("Total moves: %u\n", data->mov_count++);
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
			x += SIZE;
			j++;
		}
		y += SIZE;
		i++;
	}
}
