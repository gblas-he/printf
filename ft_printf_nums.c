/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 16:15:17 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/24 18:39:08 by gblas-he         ###   ########.fr       */
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
	count += nb = (nb % 10) + '0';
	count += write(1, &nb, 1);
	return (count);
}

int	ft_putnbr_unsing(unsigned int nb)
{
	if (nb >= 10)
		ft_putnbr_unsing(nb / 10);
	nb = (nb % 10) + '0';
	return (write(1, &nb, 1));
}

int	ft_putnbr_hexa(unsigned long num, int mayus)
{
	unsigned long	n;
	char			*base;
	int				count;

	count = 0;
	if (mayus == 1)
		base = "0123456789ABCDF";
	else
		base = "0123456789abcdf";
	n = (unsigned long)num;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= 16)
		count += ft_putnbr_hexa(n / 16, mayus);
	count += n = base[n % 16];
	count += write(1, &n, 1);
	return (count);
}

int	ft_putnbr_ptr(unsigned long num)
{
	int	count;

	count = 0;
	if (!num)
		return (write(1, "(nill)", 6));
	count += write(1, "0x", 2);
	count += ft_putnbr_hexa(num, 0);
	return (count);
}
