/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:41:24 by alermolo          #+#    #+#             */
/*   Updated: 2024/02/02 13:36:28 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	create_enemy(t_data *data)
{
	int	x;
	int	y;

	srandom(time(NULL));
	if (data->has_empty)
	{
		while (1)
		{
			x = (int)(random()) % (data->map_w - 1) / SIZE;
			y = (int)(random()) % (data->map_h - 1) / SIZE;
			if (data->map[y][x] == '0' && (y != data->player.y / SIZE
					|| x != data->player.x / SIZE))
			{
				mlx_put_image_to_window(data->mlx, data->win,
					data->img.enemy_r1.addr, x * SIZE, y * SIZE);
				data->map[y][x] = 'X';
				break ;
			}
		}
		data->enemy.x = x;
		data->enemy.y = y;
		mlx_do_sync(data->mlx);
	}
}

static void	move_enemy_left(t_data *data, int x, int y)
{
	int	i;

	i = 0;
	mlx_put_image_to_window(data->mlx, data->win,
		data->img.enemy_l2.addr, x * SIZE, y * SIZE);
	mlx_do_sync(data->mlx);
	while (i < 35000000)
		i++;
	mlx_put_image_to_window(data->mlx, data->win,
		data->img.enemy_l1.addr, x * SIZE, y * SIZE);
}

static void	move_enemy_right(t_data *data, int x, int y)
{
	int	i;

	i = 0;
	mlx_put_image_to_window(data->mlx, data->win,
		data->img.enemy_r2.addr, x * SIZE, y * SIZE);
	mlx_do_sync(data->mlx);
	while (i < 35000000)
		i++;
	mlx_put_image_to_window(data->mlx, data->win,
		data->img.enemy_r1.addr, x * SIZE, y * SIZE);
}

static void	print_enemy(t_data *data, int x, int y)
{
	int	i;

	i = 0;
	if (x < data->enemy.x)
		move_enemy_left(data, x, y);
	else
		move_enemy_right(data, x, y);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img.empty.addr, data->enemy.x * SIZE, data->enemy.y * SIZE);
	data->map[data->enemy.y][data->enemy.x] = '0';
	data->map[y][x] = 'X';
	data->enemy.x = x;
	data->enemy.y = y;
	mlx_do_sync(data->mlx);
}

void	move_enemy(t_data *data)
{
	int	x;
	int	y;
	int	hor_ver;

	srandom(time(NULL));
	x = data->enemy.x;
	y = data->enemy.y;
	hor_ver = (int)(random()) % 2;
	if (hor_ver == 0 && (data->map[y][x + 1] == '0'
		|| data->map[y][x - 1] == '0'))
		x += (int)(random()) % 3 - 1;
	else
		y += (int)(random()) % 3 - 1;
	if (x > 0 && x < data->map_w / SIZE && y > 0 && y < data->map_h / SIZE)
	{
		if (y == data->player.y / SIZE && x == data->player.x / SIZE)
			lose_msg(data);
		if (data->map[y][x] == '0')
		{
			print_enemy(data, x, y);
		}
	}
}
