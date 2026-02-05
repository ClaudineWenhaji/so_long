/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:10:45 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/04 17:48:51 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlcat(char *dest, char *src, int size)
{
	int	i;
	int	dest_len;
	int	src_len;
	int	result;

	i = 0;
	result = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size > dest_len)
		result = dest_len + src_len;
	else
		return (src_len + size);
	while (src[i] && (dest_len + 1) < size)
		dest[dest_len++] = src[i++];
	dest[dest_len] = '\0';
	return (result);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	len;

	len = ft_strlen(s);
	write(fd, s, len);
	write(fd, "\n", 1);
}

void	*ft_memcpy(void *dest, void *src, int n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	int				i;

	if (!dest && !src)
		return (NULL);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}
