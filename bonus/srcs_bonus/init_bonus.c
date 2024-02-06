/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:31:04 by alermolo          #+#    #+#             */
/*   Updated: 2024/02/06 14:48:26 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_collectibles(t_data *data)
{
	data->img.item.addr = NULL;
	data->img.item2.addr = NULL;
	data->img.item3.addr = NULL;
	data->img.item4.addr = NULL;
}

void	init_player(t_data *data)
{
	data->img.player_d1.addr = NULL;
	data->img.player_d2.addr = NULL;
	data->img.player_d3.addr = NULL;
	data->img.player_l1.addr = NULL;
	data->img.player_l2.addr = NULL;
	data->img.player_l3.addr = NULL;
	data->img.player_r1.addr = NULL;
	data->img.player_r2.addr = NULL;
	data->img.player_r3.addr = NULL;
	data->img.player_u1.addr = NULL;
	data->img.player_u2.addr = NULL;
	data->img.player_u3.addr = NULL;
}

void	init_exit(t_data *data)
{
	data->img.exit.addr = NULL;
	data->img.exit1.addr = NULL;
}

void	init_enemy(t_data *data)
{
	data->img.enemy_r1.addr = NULL;
	data->img.enemy_r2.addr = NULL;
	data->img.enemy_l1.addr = NULL;
	data->img.enemy_l2.addr = NULL;
}
