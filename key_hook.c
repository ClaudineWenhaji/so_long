/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:21:33 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/05 22:14:00 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

int	key_hook(int keycode, t_game *game)
{
	if (!game)
		return (0);
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_UP || keycode == KEY_W)
		move_player(game, 0, -1);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move_player(game, 0, 1);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move_player(game, -1, 0);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move_player(game, 1, 0);
	return (0);
}
