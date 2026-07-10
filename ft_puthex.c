/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:21:08 by ferde-so          #+#    #+#             */
/*   Updated: 2026/06/23 15:19:30 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char type)
{
	char		c;
	int			count;
	const char	*set;

	if (type == 'X')
		set = "0123456789ABCDEF";
	else
		set = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count += ft_puthex(n / 16, type);
	}
	c = set[n % 16];
	write(1, &c, 1);
	count++;
	return (count);
}
