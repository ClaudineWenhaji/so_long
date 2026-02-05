/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:21:08 by clwenhaj          #+#    #+#             */
/*   Updated: 2025/11/18 11:34:01 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The string pointed to by format specifies
// how subsequent arguments will be displayed

#include "ft_printf.h"

int	ft_handle_conversion(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			nbr_of_chrs_written;

	i = 0;
	nbr_of_chrs_written = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			nbr_of_chrs_written += ft_handle_conversion(format[i], args);
		}
		else
			nbr_of_chrs_written += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (nbr_of_chrs_written);
}
