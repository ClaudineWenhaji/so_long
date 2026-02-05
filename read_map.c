/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:52:05 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/05 23:09:10 by clwenhaj         ###   ########.fr       */
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

	while ((line = get_next_line(fd)))
		free(line);
}

char	**read_map(int fd, t_game *game)
{
	char	*line;
	char	**map;
	int		lines;
	int		width;

	lines = 0;
	map = NULL;
	line = get_next_line(fd);
	if (!line || ft_strlen(line) == 0)
		error_exit(game, "Error\nEmpty map");
	map = append_line(map, line, lines++);
	if (!map)
		error_exit(game, "Error\nMalloc failed");
	width = ft_strlen(map[0]);
	while ((line = get_next_line(fd)))
	{
		map = append_line(map, line, lines++);
		if (!map || (int)ft_strlen(map[lines - 1]) != width)
		{
			free(line);
			if (map)
				free_str_arr(map, lines - 1);
			flush_gnl(fd);
			error_exit(game, "Error\nMap is not rectangular");
			return (NULL);
		}
	}
	return (map);
}
