/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:53:52 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/05 20:24:59 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangle(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != game->width)
			error_exit("Error\nMap is not rectangle");
		i++;
	}
}
