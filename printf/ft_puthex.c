/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:21:27 by clwenhaj          #+#    #+#             */
/*   Updated: 2025/11/18 12:45:51 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, int uppercase)
{
	char	*base;
	int		i;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	if (n >= 16)
		i = i + ft_puthex(n / 16, uppercase);
	i = i + ft_putchar(base[n % 16]);
	return (i);
}
/*
#include <stdio.h>
#include<unistd.h>
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	main(void)
{
	ft_puthex(255, 0);
	write(1, "\n", 1);
	ft_puthex(4096, 0);
	write(1, "\n", 1);
	ft_puthex(3735928559UL, 1);
	write(1, "\n", 1);

	return (0);
}*/
