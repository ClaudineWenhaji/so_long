/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:11:08 by clwenhaj          #+#    #+#             */
/*   Updated: 2025/11/17 21:01:02 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nbr;
	int		i;

	nbr = n;
	i = 0;
	if (nbr < 0)
	{
		i = i + ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		i = i + ft_putnbr(nbr / 10);
	i = i + ft_putchar((nbr % 10) + '0');
	return (i);
}
