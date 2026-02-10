/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:11:04 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/10 14:07:55 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	initialization(t_game *game)
{
	game->map = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->img_wall = NULL;
	game->img_floor = NULL;
	game->img_player = NULL;
	game->img_collect = NULL;
	game->img_exit = NULL;
	game->height = 0;
	game->width = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->y2 = -1;
	game->x2 = -1;
}

int	main(int ac, char **av)
{
	t_game	game;

	initialization(&game);
	if (ac != 2)
		error_exit(&game, "Error\nWrong number of arguments");
	parse_map(av[1], &game);
	check_map(&game);
	flood_fill(&game);
	if (game.y2 >= 0 && game.x2 >= 0)
		game.map[game.y2][game.x2] = 'E';
	flood_fill_2(&game);
	print_map(game.map);
	init_game(&game);
	mlx_loop(game.mlx);
	close_game(&game);
	return (0);
}
