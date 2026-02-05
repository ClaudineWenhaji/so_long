/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:22:03 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/05 22:09:25 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "so_long.h"
#include "mlx/mlx.h"

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	game->mlx = NULL;
	free_map(game->map);
	exit(0);
	return (0);
}*/

#include "so_long.h"
#include "mlx/mlx.h"

int close_game(t_game *game)
{
	if (!game)
		exit(0);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_collect)
		mlx_destroy_image(game->mlx, game->img_collect);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);

	if (game->win) mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	if (game->map)
	{
		int i = 0;
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
		game->map = NULL;
	}

	exit(0);
	return (0);
}