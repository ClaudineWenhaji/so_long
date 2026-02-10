/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:03:18 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/09 13:29:44 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

int	render_map(t_game *game)
{
	int	x;
	int	y;

	if (!game || !game->mlx || !game->win)
		return (0);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			put_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
	return (1);
}

void	put_tile(t_game *game, char c, int x, int y)
{
	void	*img;

	if (!game || !game->mlx)
		return ;
	img = NULL;
	if (c == '1')
		img = game->img_wall;
	else if (c == '0')
		img = game->img_floor;
	else if (c == 'P')
		img = game->img_player;
	else if (c == 'E')
		img = game->img_exit;
	else if (c == 'C')
		img = game->img_collect;
	if (img)
		mlx_put_image_to_window(
			game->mlx,
			game->win,
			img,
			x * TILE_SIZE,
			y * TILE_SIZE);
}
