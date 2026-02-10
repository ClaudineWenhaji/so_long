/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:10:47 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/10 14:12:33 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map_2(t_game *game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (game->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < game->height)
	{
		copy[i] = ft_strdup(game->map[i]);
		if (!copy[i])
		{
			while (i > 0)
			{
				free(copy[i - 1]);
				i--;
			}
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_2(char **map, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_2(map, x + 1, y, game);
	flood_2(map, x - 1, y, game);
	flood_2(map, x, y + 1, game);
	flood_2(map, x, y - 1, game);
}

static int	check_access_2(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	flood_fill_2(t_game *game)
{
	char	**map_copy;

	map_copy = copy_map_2(game);
	if (!map_copy)
		error_exit(game, "Error\nMalloc failed");
	flood_2(map_copy, game->player_x, game->player_y, game);
	if (!check_access_2(map_copy))
	{
		free_map(map_copy);
		error_exit(game, "Error\nMap is not solvable");
	}
	free_map(map_copy);
}
