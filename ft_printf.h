/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:08:18 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/25 10:37:46 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(int nb);
int		ft_putnbr_unsing(unsigned int nb);
int		ft_putnbr_hexa(unsigned long num, int mayus);
int		ft_putnbr_ptr(unsigned long num);

#endif