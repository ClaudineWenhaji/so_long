/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:55:38 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/05 22:10:02 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	error_exit(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}
*/
void error_exit(t_game *game, char *msg)
{
	ft_putendl_fd(msg, 2);
	if (game)
		close_game(game);
	exit(1);
}