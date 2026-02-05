/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:00:50 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/05 22:52:59 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// stocke dimensions et compte les elements

#include "so_long.h"

int	has_ber_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4)
		return (0);
	if (ft_strcmp(file + len - 4, ".ber") == 0)
		return (1);
	return (0);
}

void	parse_map(char *file, t_game *game)
{
	int	fd;

	if (!has_ber_extension(file))
		error_exit(game, "Error\nWrong file extension");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit(game, "Error\nCannot open file");
	game->map = read_map(fd, game);
	close(fd);
	if (!game->map)
		exit(EXIT_FAILURE);
	game->height = 0;
	while (game->map[game->height])
		game->height++;
	if (!game->map[0] || ft_strlen(game->map[0]) == 0)
	{
		free_str_arr(game->map, game->height);
		error_exit(game, "Error\nEmpty map");
	}
	game->width = ft_strlen(game->map[0]);
	game->collectibles = 0;
	game->moves = 0;
}
