/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:59:38 by ferde-so          #+#    #+#             */
/*   Updated: 2026/06/23 15:32:54 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type(char type, va_list *args)
{
	void	*pointer;

	if (type == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (type == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (type == 'p')
	{
		pointer = va_arg(*args, void *);
		if (!pointer)
			return (ft_putstr("(nil)"));
		ft_putstr("0x");
		return (2 + ft_putptr(pointer));
	}
	if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (type == 'u')
		return (ft_putunbr(va_arg(*args, unsigned int)));
	if (type == 'x' || type == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), type));
	if (type == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, string);
	i = 0;
	count = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%' && string[i + 1] != '\0'
			&& ft_char_in_set(string[i + 1], "cspdiuxX%"))
		{
			count += ft_type(string[i + 1], &args);
			i++;
		}
		else
		{
			count += ft_putchar(string[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
