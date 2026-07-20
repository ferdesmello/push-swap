/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:52:33 by ferde-so          #+#    #+#             */
/*   Updated: 2026/07/20 04:02:39 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function prints a character in the standard output */
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/* This function prints an integer in the standard output */
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

/* This function prints a float in the standard output */
int	ft_putflt(double n)
{
	int			count;
	long long	int_part;
	double		frac_part;
	int			precision;

	count = 0;
	precision = 6;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	n += 0.0000005;
	int_part = (long long)n;
	frac_part = n - (double)int_part;
	count += ft_putnbr(int_part);
	count += ft_putchar('.');
	while (precision-- > 0)
	{
		frac_part *= 10;
		int_part = (int)frac_part;
		count += ft_putnbr(int_part);
		frac_part -= int_part;
	}
	return (count);
}

/* This function selects which printing function to call */
static int	ft_type(char type, va_list *args)
{
	if (type == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (type == 'd')
		return (ft_putnbr(va_arg(*args, int)));
	if (type == 'f')
		return (ft_putflt(va_arg(*args, double)));
	return (0);
}

/* This function prints on the standard output */
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
			&& (string[i + 1] == 'c'
				|| string[i + 1] == 'd'
				|| string[i + 1] == 'f'))
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
