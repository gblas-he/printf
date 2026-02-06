/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:06:34 by gblas-he          #+#    #+#             */
/*   Updated: 2026/02/06 20:23:36 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <unistd.h>

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

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_printf(char const *format, ...)
{
	va_list	ptr;
	char	*newresult;

	va_start(ptr, format);
	char __attribute__((unused)) *result = va_arg(ptr, char *);
	newresult = va_arg(ptr, char *);
	char __attribute__((unused)) newnewresult = va_arg(ptr, int);
	ft_putstr(result);
	write(1, "\n", 1);
	write(1, &newresult, 1);
	write(1, "\n", 1);
	ft_putnbr(newnewresult);
	va_end(ptr);
	return (0);
}

int	main(void)
{
	char __attribute__((unused)) c = 'a';
	ft_printf("caracter: %c", "123", 'r', 123);
	printf("\n original: %s %c %d", "123", 'r', 123);
	return (0);
}