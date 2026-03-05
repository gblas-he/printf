/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:06:34 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/05 20:32:45 by gblas-he         ###   ########.fr       */
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

// void	ft_putnbr_ptr(void *p)
// {

// }

void	ft_putnbr_unsing(unsigned int nb)
{
	if (nb >= 10)
		ft_putnbr_unsing(nb / 10);
	nb = (nb % 10) + '0';
	write(1, &nb, 1);
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

void	ft_putnbr_hexa(unsigned int num, int mayus)
{
	unsigned long	n;
	char			*base;

	if (mayus == 1)
		base = "0123456789ABCDF";
	else
		base = "0123456789abcdf";
	n = (unsigned long)num;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 16)
		ft_putnbr_hexa(n / 16, mayus);
	n = base[n % 16];
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
	// else if (f == 'p')
	// 	ft_putnbr_ptr(va_arg(args, void *));
	else if (f == 'd' || f == 'i')
		ft_putnbr(va_arg(args, int));
	else if (f == 'u')
		ft_putnbr_unsing(va_arg(args, unsigned int));
	else if (f == 'x')
		ft_putnbr_hexa(va_arg(args, unsigned int), 0);
	else if (f == 'X')
		ft_putnbr_hexa(va_arg(args, unsigned int), 1);
	else if (f == '%')
		ft_putchar('%');
}

int	ft_printf(char const *format, ...)
{
	size_t	i;
	va_list	args;

	i = 0;
	if (!format)
		return (-1);
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
	int n = 42;
	int n2 = -42;
	int *p2 = &n;

	// ft_printf("ft_printf: string %s, caracter %c, decimal %d\n", "123", 'r',
	// 	123);
	// printf("original: string %s, caracter %c, decimal %d\n", "123", 'r',
	// 123);
	ft_printf("ft_puntero: %s, %d, %x, %X, %%, %u\n", p, *p2, n, n, n2);
	printf("puntero: %s, %d, %x, %X, %%, %u", p, *p2, n, n, n2);
	return (0);
}