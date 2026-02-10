# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clwenhaj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/10 14:22:25 by clwenhaj          #+#    #+#              #
#    Updated: 2026/02/10 14:22:30 by clwenhaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

MLX_DIR = mlx
MLX_LIB = ${MLX_DIR}/libmlx.a
MLX_FLAGS	= -L${MLX_DIR} -lmlx -lXext -lX11 -lm -lz

RM = rm -f

SRCS = so_long.c \
		parse_map.c \
		render_map.c \
		check_map.c \
		read_map.c \
		check_walls.c \
		check_chars.c \
		flood_fill.c \
		flood_fill_2.c \
		free_map.c \
		init_game.c \
		init_images.c \
		key_hook.c \
		move_player.c \
		close_game.c \
		error_exit.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_strcmp.c \
		print_map.c \
		utils_libft.c \
		printf/ft_printf.c \
		printf/ft_print_pointer.c \
		printf/ft_putchar.c \
		printf/ft_puthex.c \
		printf/ft_putnbr.c \
		printf/ft_putstr.c \
		printf/ft_putunbr.c 

OBJS	= ${SRCS:.c=.o}


all: ${NAME}

${NAME}: ${OBJS} ${MLX_LIB}
	${CC} ${CFLAGS} ${OBJS} ${MLX_FLAGS} -o ${NAME}

${MLX_LIB}:
	make -C ${MLX_DIR}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
