/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:55:54 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/05 22:39:56 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game)
{
	char	**map_copy;

	map_copy = copy_map(game);
	if (!map_copy)
		error_exit(game, "Error\nMalloc failed");
	flood(map_copy, game->player_x, game->player_y, game->width, game->height);
	if (!check_access(map_copy))
		{
				free_map(map_copy);
				error_exit(game, "Error\nMap is not solvable");
		}
	free_map(map_copy);
}

char	**copy_map(t_game *game)
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

static void	flood(char **map, int x, int y, int width, int height)
{
	if (x < 0 || y < 0 || x >= width || y >= height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood(map, x + 1, y, width, height);
	flood(map, x - 1, y, width, height);
	flood(map, x, y + 1, width, height);
	flood(map, x, y - 1, width, height);
}

static int	check_access(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}