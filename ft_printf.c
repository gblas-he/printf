/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:06:34 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/21 21:29:40 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_condition(char f, va_list args)
{
	int	count;

	count = 0;
	if (f == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (f == 's')
		count += ft_putstr(va_arg(args, char *));
	// else if (f == 'p')
	// 	count += ft_putnbr_ptr(va_arg(args, unsigned long));
	// else if (f == 'd' || f == 'i')
	// 	count += ft_putnbr(va_arg(args, int));
	// else if (f == 'u')
	// 	count += ft_putnbr_unsing(va_arg(args, unsigned int));
	// else if (f == 'x')
	// 	count += ft_putnbr_hexa(va_arg(args, unsigned int), 0);
	// else if (f == 'X')
	// 	count += ft_putnbr_hexa(va_arg(args, unsigned int), 1);
	else if (f == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(char const *format, ...)
{
	size_t	i;
	va_list	args;
	int		count;

	count = 0;
	i = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_condition(format[i], args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
