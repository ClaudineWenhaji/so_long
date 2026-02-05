/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:55:12 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/05 22:32:57 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(t_game *game)
{
	int	x;
	int	y;

	
	x = 0;
	while (x < game->width)
	{
		if (game->map[0][x] != '1'
			|| game->map[game->height - 1][x] != '1')
				error_exit(game, "Error\nMap not closed by walls");
		x++;
	}
	y = 0;
	while (y < game->height)
	{
		if (game->map[y][0] != '1'
			|| game->map[y][game->width - 1] != '1')
			error_exit(game, "Error\nMap not closed by walls");
		y++;
	}
}
