/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:58:16 by clwenhaj          #+#    #+#             */
/*   Updated: 2025/11/18 12:58:09 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// typical hexadecimal format for pointer: 0x7ffee4b9...
// Print the "0x" prefix used for hexadecimal pointer notation.
// Add the number of printed characters (2) to i
// Cast the pointer to unsigned long so it can be printed as a number.
// The second parameter (0) in ft_puthex = lowercase hex.
// Add the number of characters printed by ft_puthex to the counter
// Return the total number of printed characters.

#include "ft_printf.h"

int	ft_print_pointer(void *ptr)
{
	int	i;

	if (!ptr)
		return (write(1, "(nil)", 5));
	i = 0;
	i = i + write(1, "0x", 2);
	i = i + ft_puthex((unsigned long)ptr, 0);
	return (i);
}
/*
#include <stdio.h>
#include <unistd.h>

int     ft_putchar(char c)
{
        return (write(1, &c, 1));
}

int     ft_puthex(unsigned long n, int uppercase)
{
        char    *base;
        int             i;

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

int main(void)
{
    int x = 123;
    int *ptr = &x;
    int *null_ptr = NULL;

    write(1, "Test 1: normal pointer\n", 24);
    printf("printf: %p\n", (void *)ptr);
    write(1, "ft_printf: ", 11);
    ft_print_pointer(ptr);
    write(1, "\n\n", 2);

    write(1, "Test 2: NULL pointer\n", 22);
    printf("printf: %p\n", (void *)null_ptr);
    write(1, "ft_printf: ", 11);
    ft_print_pointer(null_ptr);
    write(1, "\n\n", 2);

    write(1, "Test 3: random addresses\n", 26);
    printf("printf: %p\n", (void *)0x1234abcd);
    write(1, "ft_printf: ", 11);
    ft_print_pointer((void *)0x1234abcd);
    write(1, "\n", 1);

    return (0);
}*/
