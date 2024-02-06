# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 19:17:58 by alermolo          #+#    #+#              #
#    Updated: 2024/02/02 17:11:31 by alermolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--variables-------------------------------------------------------------------#

NAME		=	so_long
DEBUG		=	no
BONUS		=	no

#--includes & libraries--------------------------------------------------------#

INC_DIR			=	includes/
B_INC_DIR		=	bonus/includes_bonus/
LIB_DIR			=	libs
LIBFT_DIR		=	$(LIB_DIR)/libft
HEADERS 		=	includes/so_long.h
HEADERS_BONUS 	= 	bonus/includes_bonus/so_long_bonus.h

#--sources & objects-----------------------------------------------------------#

SRC_DIR		=		srcs/
B_SRC_DIR	=		bonus/srcs_bonus
OBJ_DIR		=		.objects
SOURCES 	=		srcs/main.c			\
					srcs/parse_map.c	\
					srcs/print.c		\
					srcs/movement.c		\
					srcs/free.c			\
					srcs/error.c		\
					srcs/check_map.c	\
					srcs/check_chars.c	\

SOURCES_BONUS 	=	bonus/srcs_bonus/main_bonus.c			\
					bonus/srcs_bonus/parse_map_bonus.c		\
					bonus/srcs_bonus/print_bonus.c			\
					bonus/srcs_bonus/player_bonus.c			\
					bonus/srcs_bonus/free_bonus.c			\
					bonus/srcs_bonus/message_bonus.c			\
					bonus/srcs_bonus/check_map_bonus.c		\
					bonus/srcs_bonus/check_chars_bonus.c	\
					bonus/srcs_bonus/loop_hook_bonus.c		\
					bonus/srcs_bonus/moves_bonus.c			\
					bonus/srcs_bonus/enemy_bonus.c			\
					bonus/srcs_bonus/init_bonus.c			\

#--mlx-------------------------------------------------------------------------#

MLX_DIR 	=	$(LIB_DIR)/mlx

#--flags-----------------------------------------------------------------------#

ifeq ($(BONUS), no)
CFLAGS		=	-Wall -Wextra -Werror -I $(LIBFT_DIR) -I $(MLX_DIR) -I $(INC_DIR)
else
CFLAGS		=	-Wall -Wextra -Werror -I $(LIBFT_DIR) -I $(MLX_DIR) -I $(B_INC_DIR)
endif

DFLAGS		=	-g3 -fsanitize=address
MLX_FLAGS	=	-L $(MLX_DIR)

#--debug & define flags--------------------------------------------------------#

ifeq ($(DEBUG), yes)
CFLAGS 		+=	$(DFLAGS)
endif

#--mlx flags-------------------------------------------------------------------#

MLX_FLAGS 	+= -l m -l Xext -l X11 -I $(MLX_DIR)

#--libs------------------------------------------------------------------------#

LIBFT	=	$(LIBFT_DIR)/libft.a
MLX		=	$(MLX_DIR)/libmlx.a

#--objects---------------------------------------------------------------------#

ifeq ($(BONUS), no)
OBJECTS	=	$(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))
else
OBJECTS	=	$(addprefix $(OBJ_DIR)/, $(SOURCES_BONUS:.c=.o))
endif

#--global rules----------------------------------------------------------------#

.DEFAULT_GOAL = all

#--compilation rules-----------------------------------------------------------#

all:
	$(MAKE) libs
	$(MAKE) $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(MLX)
	$(CC) $^ $(CFLAGS) $(LIBFT) $(MLX) -o $@ $(MLX_FLAGS)

ifeq ($(BONUS), no)
$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@ mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
else
$(OBJ_DIR)/%.o: %.c $(HEADERS_BONUS)
	@ mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
endif


#--libs, debugs & bonus--------------------------------------------------------#

libs:
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)

debug:
	$(MAKE) re DEBUG=yes

bonus:
	$(MAKE) BONUS=yes

#--re, clean & fclean----------------------------------------------------------#

re:
	$(MAKE) fclean
	$(MAKE) all

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) -rf $(OBJECTS)

fclean:
	$(MAKE) clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

#--norminette------------------------------------------------------------------#

norm:
	norminette $(INC_DIR) $(LIBFT_DIR) $(SRC_DIR) $(B_INC_DIR) $(B_SRC_DIR)

#--PHONY-----------------------------------------------------------------------#

.PHONY: all libs debug bonus re clean fclean norm
