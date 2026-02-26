/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:06:34 by gblas-he          #+#    #+#             */
/*   Updated: 2026/02/26 15:31:20 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <unistd.h>

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	nb = (nb % 10) + '0';
	write(1, &nb, 1);
}

void	ft_putnbr_hexa(void *p)
{
	unsigned long n = (unsigned long)p;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 16)
		ft_putnbr_hexa(n / 16);
	if (n < 10)
		 n = (n % 16) + '0';
	n = (n % 16) - 10 + 'A';
	write(1, &n, 1);
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

static void	ft_condition(char f, va_list args)
{
	if (f == 'c')
		ft_putchar(va_arg(args, int));
	else if (f == 's')
		ft_putstr(va_arg(args, char *));
	else if (f == 'p')
		ft_putnbr_hexa(va_arg(args, void *));
	else if (f == 'd')
		ft_putnbr(va_arg(args, int));
}

int	ft_printf(char const *format, ...)
{
	size_t	i;
	va_list	args;

	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_condition(format[++i], args);
			i++;
		}
		ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	char *p = "hola";
	int n = 2;
	int *p2 = &n;
	ft_printf("ft_printf: string %s, caracter %c, decimal %d\n", "123", 'r',
		123);
	printf("original: string %s, caracter %c, decimal %d\n", "123", 'r',
		123);
	ft_printf("ft_puntero: %p, %s, %p, %d\n", p, p, p2, *p2);
	printf("puntero: %p, %s, %p, %d", p, p, p2, *p2);
	return (0);
}