/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:38:53 by ferde-so          #+#    #+#             */
/*   Updated: 2026/06/23 14:59:33 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_char_in_set(const char c, const char *set);
int	ft_printf(const char *string, ...);
int	ft_putchar(char c);
int	ft_puthex(unsigned int n, char type);
int	ft_putnbr(int n);
int	ft_putptr(void *p);
int	ft_putstr(char *s);
int	ft_putunbr(unsigned int n);

#endif // FT_PRINTF_H
