/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:04:26 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/04 17:50:46 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_fill(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && !(ft_strchr(stash, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

static char	*extract_line(char *stash)
{
	char	*line;
	size_t	i;

	i = 0;
	if (stash[0] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*clean_stash(char *stash)
{
	char	*new_stash;
	size_t	i;
	size_t	j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(ft_strlen(stash) - i);
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	i++;
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_fill(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}
/*
#include <stdio.h>
#include "get_next_line.h"
#include "get_next_line_bonus.h"

int     main(void)
{
        int fd = open("../../../fichier.txt", O_RDONLY);
        
	char    *line;

        line = get_next_line(fd);
        while (line)
        {
                printf("%s", line);
                free(line);
                line = get_next_line(fd);
        }
        close(fd);
        return (0);
}

int     main(void)
{
        int fd1 = open("../../fichier.txt", O_RDONLY);
        int fd2 = open("../../main.c", O_RDONLY);

        char *line1;
        char *line2;

        while (1)
        {
                line1 = get_next_line(fd1);
                line2 = get_next_line(fd2);

                if (line1)
                {
                        printf("FD1: [%s]\n", line1);
                        free(line1);
                }
                if (line2)
                {
                        printf("FD2: [%s]\n", line2);
                        free(line2);
                }
        }

        close(fd1);
        close(fd2);

        return (0);
}*/
