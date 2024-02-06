/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:59:03 by alermolo          #+#    #+#             */
/*   Updated: 2024/02/02 13:29:18 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	cross_close(t_data *data)
{
	free_and_exit(data, EXIT_SUCCESS);
	return (0);
}

static void	coin_animation(t_data *data, int x, int y, int frame)
{
	if (frame / 7500 == 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.item.addr, x, y);
	if (frame / 7500 == 1)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.item2.addr, x, y);
	if (frame / 7500 == 2)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.item3.addr, x, y);
	if (frame / 7500 == 3)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.item4.addr, x, y);
}

static void	delay_move_enemy(t_data *data)
{
	static clock_t	last = 0;
	clock_t			now;

	now = clock();
	if (now - last > 150000)
	{
		move_enemy(data);
		last = now;
	}
}

int	loop_hook(t_data *data)
{
	int				y;
	int				x;
	static int		frame;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'C')
				coin_animation(data, x * SIZE, y * SIZE, frame++);
			if (data->map[y][x] == 'X' && data->has_empty)
				delay_move_enemy(data);
			x++;
		}
		y++;
	}
	if (frame > 30000)
		frame = 0;
	return (0);
}
