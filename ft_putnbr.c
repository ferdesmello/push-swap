/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:15:37 by ferde-so          #+#    #+#             */
/*   Updated: 2026/06/23 14:21:23 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long int	long_n;
	char		c;
	int			count;

	long_n = n;
	count = 0;
	if (long_n < 0)
	{
		write(1, "-", 1);
		long_n = -long_n;
		count++;
	}
	if (long_n > 9)
	{
		count += ft_putnbr(long_n / 10);
	}
	c = (long_n % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}
