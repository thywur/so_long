/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:11:17 by alermolo          #+#    #+#             */
/*   Updated: 2024/02/06 13:54:13 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/mlx/mlx.h"
# include "../libs/mlx/mlx_int.h"
# include "../libs/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdio.h>

# define EMPTY_PATH		"./assets/64x64/grass_2.xpm"
# define WALL_PATH		"./assets/64x64/wall.xpm"
# define ITEM_PATH		"./assets/64x64/coin.xpm"
# define EXIT_PATH		"./assets/64x64/door_b.xpm"
# define PLAYER_PATH	"./assets/64x64/hero_d2.xpm"

# define SIZE	64

typedef struct s_spr_data
{
	void	*addr;
	int		width;
	int		height;
}	t_spr_data;

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_spr
{
	t_spr_data	empty;
	t_spr_data	wall;
	t_spr_data	item;
	t_spr_data	exit;
	t_spr_data	player;
}	t_spr;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	char			**map;
	char			**map_check;
	int				map_w;
	int				map_h;
	t_spr			img;
	t_coords		player;
	t_coords		exit;
	int				c_count;
	int				exit_open;
	unsigned int	mov_count;
}	t_data;

void	parse_map(t_data *data, char *map_path);
void	print_map(t_data *data);
void	put_sprite(t_data *data, int x, int y, char c);
int		key_hook(int keycode, t_data *data);
int		cross_close(t_data *data);
void	free_and_exit(t_data *data, int exit_status);
void	err_msg(t_data *data, char *err);
int		map_valid(t_data *data);
int		chars_valid(t_data *data);

#endif
