/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 16:15:17 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/25 10:38:45 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	nb = (nb % 10) + '0';
	count += write(1, &nb, 1);
	return (count);
}

int	ft_putnbr_unsing(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_putnbr_unsing(nb / 10);
	nb = (nb % 10) + '0';
	count += write(1, &nb, 1);
	return (count);
}

int	ft_putnbr_hexa(unsigned long num, int mayus)
{
	char			*base;
	int				count;

	count = 0;
	if (mayus == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (num >= 16)
		count += ft_putnbr_hexa(num / 16, mayus);
	num = base[num % 16];
	count += write(1, &num, 1);
	return (count);
}

int	ft_putnbr_ptr(unsigned long num)
{
	int	count;

	count = 0;
	if (!num)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += ft_putnbr_hexa(num, 0);
	return (count);
}
