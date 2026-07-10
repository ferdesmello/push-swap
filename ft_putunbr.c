/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:15:37 by ferde-so          #+#    #+#             */
/*   Updated: 2026/06/23 14:23:20 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n > 9)
	{
		count += ft_putunbr(n / 10);
	}
	c = (n % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}
