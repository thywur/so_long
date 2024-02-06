/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:13:45 by alermolo          #+#    #+#             */
/*   Updated: 2024/01/31 17:02:43 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static void	free_player(t_data *data)
{
	if (data->img.player_r1.addr)
		mlx_destroy_image(data->mlx, data->img.player_r1.addr);
	if (data->img.player_r2.addr)
		mlx_destroy_image(data->mlx, data->img.player_r2.addr);
	if (data->img.player_r3.addr)
		mlx_destroy_image(data->mlx, data->img.player_r3.addr);
	if (data->img.player_l1.addr)
		mlx_destroy_image(data->mlx, data->img.player_l1.addr);
	if (data->img.player_l2.addr)
		mlx_destroy_image(data->mlx, data->img.player_l2.addr);
	if (data->img.player_l3.addr)
		mlx_destroy_image(data->mlx, data->img.player_l3.addr);
	if (data->img.player_u1.addr)
		mlx_destroy_image(data->mlx, data->img.player_u1.addr);
	if (data->img.player_u2.addr)
		mlx_destroy_image(data->mlx, data->img.player_u2.addr);
	if (data->img.player_u3.addr)
		mlx_destroy_image(data->mlx, data->img.player_u3.addr);
	if (data->img.player_d1.addr)
		mlx_destroy_image(data->mlx, data->img.player_d1.addr);
	if (data->img.player_d2.addr)
		mlx_destroy_image(data->mlx, data->img.player_d2.addr);
	if (data->img.player_d3.addr)
		mlx_destroy_image(data->mlx, data->img.player_d3.addr);
}

static void	free_enemy(t_data *data)
{
	if (data->img.enemy_r1.addr)
		mlx_destroy_image(data->mlx, data->img.enemy_r1.addr);
	if (data->img.enemy_r2.addr)
		mlx_destroy_image(data->mlx, data->img.enemy_r2.addr);
	if (data->img.enemy_l1.addr)
		mlx_destroy_image(data->mlx, data->img.enemy_l1.addr);
	if (data->img.enemy_l2.addr)
		mlx_destroy_image(data->mlx, data->img.enemy_l2.addr);
}

static void	free_collectibles(t_data *data)
{
	if (data->img.item.addr)
		mlx_destroy_image(data->mlx, data->img.item.addr);
	if (data->img.item2.addr)
		mlx_destroy_image(data->mlx, data->img.item2.addr);
	if (data->img.item3.addr)
		mlx_destroy_image(data->mlx, data->img.item3.addr);
	if (data->img.item4.addr)
		mlx_destroy_image(data->mlx, data->img.item4.addr);
}

void	free_and_exit(t_data *data, int exit_status)
{
	if (data->map)
		free_arr(data->map);
	if (data->map_check)
		free_arr(data->map_check);
	if (data->img.empty.addr)
		mlx_destroy_image(data->mlx, data->img.empty.addr);
	if (data->img.wall.addr)
		mlx_destroy_image(data->mlx, data->img.wall.addr);
	if (data->img.exit.addr)
		mlx_destroy_image(data->mlx, data->img.exit.addr);
	if (data->img.exit1.addr)
		mlx_destroy_image(data->mlx, data->img.exit1.addr);
	free_collectibles(data);
	free_player(data);
	free_enemy(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(exit_status);
}
