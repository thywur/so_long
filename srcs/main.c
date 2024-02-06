/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:22:31 by alermolo          #+#    #+#             */
/*   Updated: 2024/02/06 14:46:25 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_spr_data	new_sprite(t_data *data, char *path)
{
	t_spr_data	spr;

	if (!path)
		err_msg(data, "Invalid sprite path");
	spr.addr = mlx_xpm_file_to_image(data->mlx, path, &spr.width, &spr.height);
	if (spr.addr == NULL)
		err_msg(data, "Invalid sprite path");
	return (spr);
}

void	init_data(t_data *data)
{
	data->map = NULL;
	data->map_check = NULL;
	data->win = NULL;
	data->img.empty.addr = NULL;
	data->img.wall.addr = NULL;
	data->img.item.addr = NULL;
	data->img.exit.addr = NULL;
	data->img.player.addr = NULL;
	data->img.empty = new_sprite(data, EMPTY_PATH);
	data->img.wall = new_sprite(data, WALL_PATH);
	data->img.item = new_sprite(data, ITEM_PATH);
	data->img.exit = new_sprite(data, EXIT_PATH);
	data->img.player = new_sprite(data, PLAYER_PATH);
	data->exit_open = 0;
	data->mov_count = 0;
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
	if (!data->win)
		err_msg(data, "mlx_new_window() failed");
}

int	main(int argc, char **argv)
{
	t_data		data;

	data.mlx = mlx_init();
	if (!data.mlx)
		err_msg(&data, "mlx_init() failed");
	init_data(&data);
	if (argc != 2)
		err_msg(&data, "Please specify a single valid .ber file");
	parse_map(&data, argv[1]);
	fill_data(&data);
	print_map(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, DestroyNotify, ButtonPressMask, cross_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
