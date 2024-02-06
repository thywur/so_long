/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:05:04 by alermolo          #+#    #+#             */
/*   Updated: 2024/01/31 16:50:46 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_obst(t_data *data, int x, int y)
{
	if (data->map[y / SIZE][x / SIZE] == '1')
		return (1);
	if (data->map[y / SIZE][x / SIZE] == 'E')
	{
		if (data->exit_open == 1)
			free_and_exit(data, EXIT_SUCCESS);
		return (1);
	}
	if (data->map[y / SIZE][x / SIZE] == 'C')
	{
		data->c_count--;
		if (data->c_count == 0)
			data->exit_open = 1;
	}
	return (0);
}

int	key_hook(int key, t_data *data)
{
	if (key == 'd' && !is_obst(data, data->player.x + SIZE, data->player.y))
	{
		put_sprite(data, data->player.x + SIZE, data->player.y, 'P');
		put_sprite(data, data->player.x - SIZE, data->player.y, '0');
	}
	if (key == 'w' && !is_obst(data, data->player.x, data->player.y - SIZE))
	{
		put_sprite(data, data->player.x, data->player.y - SIZE, 'P');
		put_sprite(data, data->player.x, data->player.y + SIZE, '0');
	}
	if (key == 'a' && !is_obst(data, data->player.x - SIZE, data->player.y))
	{
		put_sprite(data, data->player.x - SIZE, data->player.y, 'P');
		put_sprite(data, data->player.x + SIZE, data->player.y, '0');
	}
	if (key == 's' && !is_obst(data, data->player.x, data->player.y + SIZE))
	{
		put_sprite(data, data->player.x, data->player.y + SIZE, 'P');
		put_sprite(data, data->player.x, data->player.y - SIZE, '0');
	}
	if (key == 65307)
		free_and_exit(data, EXIT_SUCCESS);
	return (0);
}
