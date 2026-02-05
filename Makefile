NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

MLX_DIR = mlx
MLX_LIB = ${MLX_DIR}/libmlx.a
MLX_FLAGS	= -L${MLX_DIR} -lmlx -lXext -lX11 -lm -lz

RM = rm -f

# VALGRIND = @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

VALGRIND = @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --tool=memcheck --keep-debuginfo=yes

SRCS = so_long.c \
		parse_map.c \
		render_map.c \
		check_map.c \
		read_map.c \
		check_rectangle.c \
		check_walls.c \
		check_chars.c \
		flood_fill.c \
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

run:	${NAME}
	${VALGRIND} ./${NAME} assets/maps/valid/map3.ber

#norm:
#	norminette ${SRCS} so_long.h

#.PHONY: all clean fclean re valgrind run norm

.PHONY: all clean fclean re valgrind run
