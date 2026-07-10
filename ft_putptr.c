/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:02:06 by ferde-so          #+#    #+#             */
/*   Updated: 2026/06/23 14:21:57 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *p)
{
	unsigned long	address;
	char			c;
	int				count;
	const char		*set;

	if (!p)
	{
		write(1, "0", 1);
		return (1);
	}
	set = "0123456789abcdef";
	address = (unsigned long)p;
	count = 0;
	if (address >= 16)
	{
		count += ft_putptr((void *)(address / 16));
	}
	c = set[address % 16];
	write(1, &c, 1);
	count++;
	return (count);
}
