/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:21:44 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/05 19:15:24 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"
#include "printf/ft_printf.h"

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (!can_move(game, new_x, new_y))
		return ;
	update_position(game, new_x, new_y);
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_map(game);
}

int	can_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_y < 0
		|| new_x >= game->width
		|| new_y >= game->height)
		return (0);
	if (game->map[new_y][new_x] == '1')
		return (0);
	return (1);
}

void	update_position(t_game *game, int new_x, int new_y)
{
	char	next;

	next = game->map[new_y][new_x];
	if (next == 'C')
		game->collectibles--;
	if (next == 'E')
	{
		if (game->collectibles == 0)
			close_game(game);
		return ;
	}
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
}
