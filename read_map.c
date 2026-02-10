/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:52:05 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/09 18:31:50 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	free_str_arr(char **map, int lines)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < lines)
		free(map[i++]);
	free(map);
}

static char	**append_line(char **map, char *line, int lines)
{
	char	**new_map;
	int		i;

	if (!line)
		return (NULL);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	new_map = (char **)malloc(sizeof(char *) * (lines + 2));
	if (!new_map)
	{
		free(line);
		free_str_arr(map, lines);
		return (NULL);
	}
	i = 0;
	while (i < lines)
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[i++] = line;
	new_map[i] = NULL;
	free(map);
	return (new_map);
}

void	flush_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

void	init_map(t_game *game)
{
	game->lines = 0;
	game->map = NULL;
}

char	**read_map(int fd, t_game *game)
{
	init_map(game);
	game->line = get_next_line(fd);
	if (!game->line || ft_strlen(game->line) == 0)
	{
		free(game->line);
		error_exit(game, "Error\nEmpty map");
	}
	game->map = append_line(game->map, game->line, game->lines++);
	if (!game->map)
		error_exit(game, "Error\nMalloc failed");
	game->width = ft_strlen(game->map[0]);
	game->line = get_next_line(fd);
	while (game->line)
	{
		game->map = append_line(game->map, game->line, game->lines++);
		if (!game->map
			|| (int)ft_strlen(game->map[game->lines - 1]) != game->width)
		{
			flush_gnl(fd);
			error_exit(game, "Error\nMap is not rectangular");
		}
		game->line = get_next_line(fd);
	}
	return (game->map);
}
