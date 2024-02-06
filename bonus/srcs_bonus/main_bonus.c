/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:22:31 by alermolo          #+#    #+#             */
/*   Updated: 2024/02/02 13:27:53 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_spr_data	new_sprite(t_data *data, char *path)
{
	t_spr_data	spr;

	spr.addr = mlx_xpm_file_to_image(data->mlx, path, &spr.width, &spr.height);
	if (spr.addr == NULL)
		free_and_exit(data, EXIT_FAILURE);
	return (spr);
}

static void	init_data(t_data *data)
{
	data->map = NULL;
	data->map_check = NULL;
	data->win = NULL;
	data->img.empty.addr = NULL;
	data->img.wall.addr = NULL;
	init_collectibles(data);
	init_player(data);
	init_exit(data);
	init_enemy(data);
}

static void	get_sprite_paths(t_data *data)
{
	data->img.empty = new_sprite(data, EMPTY_PATH);
	data->img.wall = new_sprite(data, WALL_PATH);
	data->img.item = new_sprite(data, ITEM_PATH);
	data->img.item2 = new_sprite(data, ITEM2_PATH);
	data->img.item3 = new_sprite(data, ITEM3_PATH);
	data->img.item4 = new_sprite(data, ITEM4_PATH);
	data->img.exit = new_sprite(data, EXIT_C_PATH);
	data->img.exit1 = new_sprite(data, EXIT_O_PATH);
	data->img.player_d1 = new_sprite(data, PLAYER_D1_PATH);
	data->img.player_d2 = new_sprite(data, PLAYER_D2_PATH);
	data->img.player_d3 = new_sprite(data, PLAYER_D3_PATH);
	data->img.player_l1 = new_sprite(data, PLAYER_L1_PATH);
	data->img.player_l2 = new_sprite(data, PLAYER_L2_PATH);
	data->img.player_l3 = new_sprite(data, PLAYER_L3_PATH);
	data->img.player_r1 = new_sprite(data, PLAYER_R1_PATH);
	data->img.player_r2 = new_sprite(data, PLAYER_R2_PATH);
	data->img.player_r3 = new_sprite(data, PLAYER_R3_PATH);
	data->img.player_u1 = new_sprite(data, PLAYER_U1_PATH);
	data->img.player_u2 = new_sprite(data, PLAYER_U2_PATH);
	data->img.player_u3 = new_sprite(data, PLAYER_U3_PATH);
	data->img.enemy_r1 = new_sprite(data, ENEMY_R1_PATH);
	data->img.enemy_r2 = new_sprite(data, ENEMY_R2_PATH);
	data->img.enemy_l1 = new_sprite(data, ENEMY_L1_PATH);
	data->img.enemy_l2 = new_sprite(data, ENEMY_L2_PATH);
}

void	fill_data(t_data *data)
{
	int		i;

	i = 0;
	data->map_w = ft_strlen(data->map[0]) * SIZE;
	while (data->map[i])
		i++;
	data->map_h = i * SIZE;
	data->win = mlx_new_window(data->mlx, data->map_w,
			data->map_h, "so_long");
	data->exit_open = 0;
	data->mov_count = 0;
	data->has_empty = 0;
}

int	main(int argc, char **argv)
{
	t_data		data;

	data.mlx = mlx_init();
	init_data(&data);
	get_sprite_paths(&data);
	if (argc != 2)
		err_msg(&data, "Please specify a single valid .ber file");
	parse_map(&data, argv[1]);
	fill_data(&data);
	print_map(&data);
	clear_player_space(&data);
	create_enemy(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, DestroyNotify, ButtonPressMask, cross_close, &data);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
