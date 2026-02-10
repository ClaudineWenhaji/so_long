/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:50:59 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/09 12:54:33 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	init_game(t_game *game)
{
	game->moves = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit(game, "Error\nMLX init failed");
	game->win = mlx_new_window(
			game->mlx,
			game->width * TILE_SIZE,
			game->height * TILE_SIZE,
			"so_long");
	if (!game->win)
		error_exit(game, "Error\nWindow creation failed");
	init_images(game);
	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_collect || !game->img_exit)
		error_exit(game, "Error\nFailed to load images");
	mlx_hook(game->win, KeyPress, KeyPressMask, key_hook, game);
	mlx_hook(game->win, DestroyNotify, 0, close_game, game);
	mlx_hook(game->win, Expose, ExposureMask, render_map, game);
	render_map(game);
}
