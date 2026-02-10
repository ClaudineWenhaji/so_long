/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:53:12 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/09 12:48:31 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check(t_game *game, char c, int x, int y)
{
	if (c == 'P')
	{
		game->player_x = x;
		game->player_y = y;
		game->p_count++;
	}
	else if (c == 'E')
		game->e_count++;
	else if (c == 'C')
		game->collectibles++;
	else if (c != '0' && c != '1')
		error_exit(game, "Error\nInvalid character in map");
}

void	check_chars(t_game *game)
{
	int	x;
	int	y;

	game->p_count = 0;
	game->e_count = 0;
	game->collectibles = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			check(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
	if (game->p_count != 1 || game->e_count != 1 || game->collectibles < 1)
		error_exit(game, "Error\nInvalid number of P, E or C");
}
