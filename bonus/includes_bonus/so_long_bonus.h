/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:11:17 by alermolo          #+#    #+#             */
/*   Updated: 2024/02/06 14:49:50 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../../libs/mlx/mlx.h"
# include "../../libs/mlx/mlx_int.h"
# include "../../libs/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <time.h>

# define EMPTY_PATH		"./bonus/assets/64x64/grass_2.xpm"
# define WALL_PATH		"./bonus/assets/64x64/wall.xpm"
# define ITEM_PATH		"./bonus/assets/64x64/coin.xpm"
# define ITEM2_PATH		"./bonus/assets/64x64/coin_2.xpm"
# define ITEM3_PATH		"./bonus/assets/64x64/coin_3.xpm"
# define ITEM4_PATH		"./bonus/assets/64x64/coin_4.xpm"
# define EXIT_C_PATH	"./bonus/assets/64x64/door_closed.xpm"
# define EXIT_O_PATH	"./bonus/assets/64x64/door_open.xpm"
# define PLAYER_D1_PATH	"./bonus/assets/64x64/hero_d1.xpm"
# define PLAYER_D2_PATH	"./bonus/assets/64x64/hero_d2.xpm"
# define PLAYER_D3_PATH	"./bonus/assets/64x64/hero_d3.xpm"
# define PLAYER_R1_PATH	"./bonus/assets/64x64/hero_r1.xpm"
# define PLAYER_R2_PATH	"./bonus/assets/64x64/hero_r2.xpm"
# define PLAYER_R3_PATH	"./bonus/assets/64x64/hero_r3.xpm"
# define PLAYER_L1_PATH	"./bonus/assets/64x64/hero_l1.xpm"
# define PLAYER_L2_PATH	"./bonus/assets/64x64/hero_l2.xpm"
# define PLAYER_L3_PATH	"./bonus/assets/64x64/hero_l3.xpm"
# define PLAYER_U1_PATH	"./bonus/assets/64x64/hero_u1.xpm"
# define PLAYER_U2_PATH	"./bonus/assets/64x64/hero_u2.xpm"
# define PLAYER_U3_PATH	"./bonus/assets/64x64/hero_u3.xpm"
# define ENEMY_R1_PATH	"./bonus/assets/64x64/slime_r1.xpm"
# define ENEMY_R2_PATH	"./bonus/assets/64x64/slime_r2.xpm"
# define ENEMY_L1_PATH	"./bonus/assets/64x64/slime_l1.xpm"
# define ENEMY_L2_PATH	"./bonus/assets/64x64/slime_l2.xpm"

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
	t_spr_data	item2;
	t_spr_data	item3;
	t_spr_data	item4;
	t_spr_data	exit;
	t_spr_data	exit1;
	t_spr_data	player_d1;
	t_spr_data	player_d2;
	t_spr_data	player_d3;
	t_spr_data	player_l1;
	t_spr_data	player_l2;
	t_spr_data	player_l3;
	t_spr_data	player_r1;
	t_spr_data	player_r2;
	t_spr_data	player_r3;
	t_spr_data	player_u1;
	t_spr_data	player_u2;
	t_spr_data	player_u3;
	t_spr_data	enemy_r1;
	t_spr_data	enemy_r2;
	t_spr_data	enemy_l1;
	t_spr_data	enemy_l2;
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
	t_coords		enemy;
	int				c_count;
	int				exit_open;
	int				has_empty;
	unsigned int	mov_count;
}	t_data;

void	parse_map(t_data *data, char *map_path);
void	print_map(t_data *data);
void	put_sprite(t_data *data, int x, int y, char c);
int		key_hook(int key, t_data *data);
int		loop_hook(t_data *data);
int		cross_close(t_data *data);
void	free_and_exit(t_data *data, int exit_status);
void	err_msg(t_data *data, char *err);
int		map_valid(t_data *data);
int		chars_valid(t_data *data);
void	fill_top_wall(t_data *data);
void	move_right(t_data *data, int x, int y);
void	move_left(t_data *data, int x, int y);
void	move_up(t_data *data, int x, int y);
void	move_down(t_data *data, int x, int y);
void	create_enemy(t_data *data);
void	move_enemy(t_data *data);
void	init_collectibles(t_data *data);
void	init_player(t_data *data);
void	init_exit(t_data *data);
void	init_enemy(t_data *data);
void	clear_player_space(t_data *data);
void	win_msg(t_data *data);
void	lose_msg(t_data *data);

#endif
