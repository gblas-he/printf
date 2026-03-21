/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 16:15:17 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/21 21:29:37 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_putnbr_unsing(unsigned int nb)
{
	if (nb >= 10)
		ft_putnbr_unsing(nb / 10);
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

void	ft_putnbr_ptr(unsigned long num)
{
	if (!num)
	{
		write(1, "(nill)", 6);
		return ;
	}
	write(1, "0x", 2);
	ft_putnbr_hexa(num, 0);
}
