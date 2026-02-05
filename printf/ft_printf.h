/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:24:09 by clwenhaj          #+#    #+#             */
/*   Updated: 2025/11/21 17:09:57 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_handle_conversion(char c, va_list args);

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int	ft_puthex(unsigned long n, int uppercase);
int	ft_print_pointer(void *ptr);

#endif
/*
#include "ft_printf.h"

int     main(void)
{
	int len1, len2;

        printf("\n\n=== TEST FT_PRINTF ===\n\n");

        // %c
        len1 = ft_printf("ft: Char test : [%c]\n", 'A');
        len2 = printf("or: Char test : [%c]\n", 'A');
        printf("Retours--> ft:%d | or:%d\n\n", len1, len2);

        // %s
        ft_printf("ft: String test : [%s]\n", "Hello 42");
        printf("or: String test : [%s]\n\n", "Hello 42");

        // %p
        int x = 42;
        ft_printf("ft: Pointer test : [%p]\n", &x);
        printf("or: Pointer test : [%p]\n\n", &x);

        // %d / %i
        ft_printf("ft: Decimal d: [%d] / i: [%i]\n", -1234, -1234);
        printf("or: Decimal d: [%d] / i: [%i]\n\n", -1234, -1234);

        // %u
        ft_printf("ft: Unsigned : [%u]\n", 3000000000U);
        printf("or: Unsigned : [%u]\n\n", 3000000000U);

        // %x / %X
        ft_printf("ft: Hex lower : [%x]\n", 3735928559U);
        ft_printf("ft: Hex upper : [%X]\n", 3735928559U);
        printf("or: Hex lower : [%x]\n", 3735928559U);
        printf("or: Hex upper : [%X]\n\n", 3735928559U);

	// %%
        ft_printf("ft: Percent: %%\n");
        printf("or: Percent: %%\n\n");

        // Null String
        ft_printf("ft: Null string: %s\n", (char *)NULL);
        printf("or: Null string: %s\n\n", (char *)NULL);

	return (0);
}*/
