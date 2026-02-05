/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:04:24 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/05 22:55:00 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include <fcntl.h>
# include <X11/X.h>

# include "get_next_line.h"
# include "printf/ft_printf.h"

# define TILE_SIZE	64	

# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_ESC	65307

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_game
{
	void	*mlx;
	void	*win;

	char	**map;
	int		width;
	int		height;

	int		player_x;
	int		player_y;

	int		collectibles;
	int		moves;
	int		p_count;
	int		e_count;

	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collect;
}	t_game;

void	parse_map(char *file, t_game *game);
int		render_map(t_game *game);
void	check_map(t_game *game);
void	check_rectangle(t_game *game);
void	check_walls(t_game *game);
void	check_chars(t_game *game);
void	check(t_game *game, char c, int x, int y);

void	flood_fill(t_game *game);
//static void	flood(char **map, int x, int y, int width, int height);

void	init_game(t_game *game);
void	init_images(t_game *game);

int		key_hook(int keycode, t_game *game);
void	move_player(t_game *game, int dx, int dy);
int		close_game(t_game *game);

void	free_map(char **map);
int		has_ber_extension(char *file);
char	**read_map(int fd, t_game *game);
int		ft_strcmp(char *s1, char *s2);
void	error_exit(t_game *game, char *msg);
//static char	**copy_map(t_game *game);
//static int		check_access(char **map);
void	put_tile(t_game *game, char c, int x, int y);
void	update_position(t_game *game, int new_x, int new_y);
int		can_move(t_game *game, int new_x, int new_y);

int		ft_strlcat(char *dest, char *src, int size);
void	ft_putendl_fd(char *s, int fd);
void	*ft_memcpy(void *dest, void *src, int n);
void	print_map(char **map);
void    free_str_arr(char **map, int lines);

#endif
