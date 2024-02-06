/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:05:04 by alermolo          #+#    #+#             */
/*   Updated: 2024/02/02 13:50:12 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	clear_player_space(t_data *data)
{
	data->map[data->player.y / SIZE][data->player.x / SIZE] = '0';
}

static int	is_obst(t_data *data, int x, int y)
{
	if (data->map[y / SIZE][x / SIZE] == '1')
		return (1);
	if (data->map[y / SIZE][x / SIZE] == 'X')
		lose_msg(data);
	if (data->map[y / SIZE][x / SIZE] == 'E')
	{
		if (data->exit_open == 1)
			win_msg(data);
		return (1);
	}
	if (data->map[y / SIZE][x / SIZE] == 'C')
	{
		data->c_count--;
		if (data->c_count == 0)
		{
			data->exit_open = 1;
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.exit1.addr, data->exit.x, data->exit.y);
		}
	}
	return (0);
}

void	move_player(t_data *data, int x, int y, int key)
{
	char	*moves;

	if (key == 'd')
		move_right(data, x, y);
	if (key == 'w')
		move_up(data, x, y);
	if (key == 'a')
		move_left(data, x, y);
	if (key == 's')
		move_down(data, x, y);
	data->player.x = x;
	data->player.y = y;
	data->map[y / SIZE][x / SIZE] = '0';
	moves = ft_itoa(++data->mov_count);
	fill_top_wall(data);
	mlx_string_put(data->mlx, data->win, 5, 15, 0x00FFFFFF, "Moves: ");
	mlx_string_put(data->mlx, data->win, 60, 15, 0x00FFFFFF, moves);
	free(moves);
}

int	key_hook(int key, t_data *data)
{
	if (key == 'd' && !is_obst(data, data->player.x + SIZE, data->player.y))
	{
		move_player(data, data->player.x + SIZE, data->player.y, 'd');
		put_sprite(data, data->player.x - SIZE, data->player.y, '0');
	}
	if (key == 'w' && !is_obst(data, data->player.x, data->player.y - SIZE))
	{
		move_player(data, data->player.x, data->player.y - SIZE, 'w');
		put_sprite(data, data->player.x, data->player.y + SIZE, '0');
	}
	if (key == 'a' && !is_obst(data, data->player.x - SIZE, data->player.y))
	{
		move_player(data, data->player.x - SIZE, data->player.y, 'a');
		put_sprite(data, data->player.x + SIZE, data->player.y, '0');
	}
	if (key == 's' && !is_obst(data, data->player.x, data->player.y + SIZE))
	{
		move_player(data, data->player.x, data->player.y + SIZE, 's');
		put_sprite(data, data->player.x, data->player.y - SIZE, '0');
	}
	if (key == 65307)
		free_and_exit(data, EXIT_SUCCESS);
	return (0);
}
