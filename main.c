/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:19:11 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/25 14:56:58 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char *p = NULL;
	int n = 0;
	int n2 = -2147483648;
	int *p2 = &n;
	char c = '0';
	ft_printf("ft_printf: %c, %s, %d, %x, %X, %%, %u, %p, %%%%\n", c, p, *p2, n,
		n, n2, p);
	printf("printf: %c, %s, %d, %x, %X, %%, %u, %p, %%%%\n", c, p, *p2, n, n,
		n2, p);
	ft_printf("%p\n", p2);
	printf("%p\n", p2);
	ft_printf("Hello %a World");
	return (0);
}