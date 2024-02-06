/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:43:41 by alermolo          #+#    #+#             */
/*   Updated: 2024/01/31 16:50:46 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_right(t_data *data, int x, int y)
{
	static int	frame;
	int			i;

	if (frame == 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player_r1.addr, x, y);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player_r3.addr, x, y);
	put_sprite(data, x - SIZE, y, '0');
	mlx_do_sync(data->mlx);
	i = 0;
	while (i < 65000000)
		i++;
	mlx_put_image_to_window(data->mlx, data->win,
		data->img.player_r2.addr, x, y);
	frame = !frame;
	data->player.x = x;
}

void	move_up(t_data *data, int x, int y)
{
	static int	frame;
	int			i;

	if (frame == 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player_u1.addr, x, y);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player_u3.addr, x, y);
	put_sprite(data, x, y + SIZE, '0');
	mlx_do_sync(data->mlx);
	i = 0;
	while (i < 65000000)
		i++;
	mlx_put_image_to_window(data->mlx, data->win,
		data->img.player_u2.addr, x, y);
	frame = !frame;
	data->player.y = y;
}

void	move_left(t_data *data, int x, int y)
{
	static int	frame;
	int			i;

	if (frame == 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player_l1.addr, x, y);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player_l3.addr, x, y);
	put_sprite(data, x + SIZE, y, '0');
	mlx_do_sync(data->mlx);
	i = 0;
	while (i < 65000000)
		i++;
	mlx_put_image_to_window(data->mlx, data->win,
		data->img.player_l2.addr, x, y);
	frame = !frame;
	data->player.x = x;
}

void	move_down(t_data *data, int x, int y)
{
	static int	frame;
	int			i;

	if (frame == 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player_d1.addr, x, y);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player_d3.addr, x, y);
	put_sprite(data, x, y - SIZE, '0');
	mlx_do_sync(data->mlx);
	i = 0;
	while (i < 65000000)
		i++;
	mlx_put_image_to_window(data->mlx, data->win,
		data->img.player_d2.addr, x, y);
	frame = !frame;
	data->player.y = y;
}
