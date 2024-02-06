# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 16:11:24 by alermolo          #+#    #+#              #
#    Updated: 2024/01/28 15:36:17 by alermolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libft.a

SRCS = 		ft_split.c			\
			ft_strlen.c			\
			ft_strchr.c			\
			ft_strrchr.c		\
			ft_strcmp.c			\
			ft_strjoin.c		\
			get_next_line.c		\
			get_next_line_utils.c	\
			ft_printf.c \
			ft_printaddr.c \
			ft_printchar.c \
			ft_printnbr_hex.c \
			ft_printnbr.c \
			ft_printstr.c \
			ft_itoa.c	\

OBJS =		$(SRCS:.c=.o)

BOBJS =		$(BSRCS:.c=.o)

HEADER =	libft.h

CC =		cc

CFLAGS =	-Wall -Werror -Wextra

RM =		rm -rf

%.o :		%.c $(HEADER)
			$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
				ar rcs $(NAME) $(OBJS)

bonus:		$(OBJS) $(BOBJS)
				ar rcs $(NAME) $(OBJS) $(BOBJS)

clean:
				$(RM) $(OBJS) $(BOBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
