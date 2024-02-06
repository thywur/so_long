/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:13:45 by alermolo          #+#    #+#             */
/*   Updated: 2024/01/25 17:08:47 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cross_close(t_data *data)
{
	free_and_exit(data, EXIT_SUCCESS);
	return (0);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
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
	if (data->img.item.addr)
		mlx_destroy_image(data->mlx, data->img.item.addr);
	if (data->img.exit.addr)
		mlx_destroy_image(data->mlx, data->img.exit.addr);
	if (data->img.player.addr)
		mlx_destroy_image(data->mlx, data->img.player.addr);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(exit_status);
}
