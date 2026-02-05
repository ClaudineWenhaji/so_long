/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:53:31 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/05 20:25:22 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_game *game)
{
	if (!game->map || !game->map[0])
			error_exit("Error\nEmpty map");
	check_rectangle(game);
	check_chars(game);
	check_walls(game);
}
