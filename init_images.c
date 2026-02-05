/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:57:33 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/05 22:43:01 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	init_images(t_game *game)
{
	int	width;
	int	height;

	game->img_wall = mlx_xpm_file_to_image(
			game->mlx, "assets/sprites/wall.xpm", &width, &height);
	game->img_floor = mlx_xpm_file_to_image(
			game->mlx, "assets/sprites/floor.xpm", &width, &height);
	game->img_player = mlx_xpm_file_to_image(
			game->mlx, "assets/sprites/player.xpm", &width, &height);
	game->img_exit = mlx_xpm_file_to_image(
			game->mlx, "assets/sprites/exit.xpm", &width, &height);
	game->img_collect = mlx_xpm_file_to_image(
			game->mlx, "assets/sprites/collectible.xpm", &width, &height);
	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_exit || !game->img_collect)
	
		error_exit(game, "Error\nFailed to load images");
}
