/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:11:04 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/05 22:32:21 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// verifie les arguments

#include "so_long.h"
#include "mlx/mlx.h"

int	main(int ac, char **av)
{
	t_game	game;

	game.map        = NULL;
	game.mlx        = NULL;
	game.win        = NULL;
	game.img_wall   = NULL;
	game.img_floor  = NULL;
	game.img_player = NULL;
	game.img_collect= NULL;
	game.img_exit   = NULL;

	if (ac != 2)
		error_exit(&game, "Error\nWrong number of arguments");
	parse_map(av[1], &game);
	check_map(&game);
	flood_fill(&game);
	print_map(game.map);
	init_game(&game);
	mlx_loop(game.mlx);
	close_game(&game);	
	return (0);
}