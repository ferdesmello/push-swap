/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_strategy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <isabelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 15:28:26 by isabelle          #+#    #+#             */
/*   Updated: 2026/07/30 01:32:16 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static void	print_adaptive(float disorder)
{
	char	*s_text;
	char	*m_text;
	char	*c_text;

	s_text = "[bench] strategy:  Adaptive / O(n²)\n";
	m_text = "[bench] strategy:  Adaptive / O(n√n)\n";
	c_text = "[bench] strategy:  Adaptive / O(n log n)\n";
	if (disorder < 0.2)
		write(2, s_text, ft_strlen(s_text));
	else if (disorder < 0.5)
		write(2, m_text, ft_strlen(m_text));
	else
		write(2, c_text, ft_strlen(c_text));
}

void	bench_print_strategy(t_bench *bench)
{
	char	*s_text;
	char	*m_text;
	char	*c_text;

	s_text = "[bench] strategy:  Simple / O(n²)\n";
	m_text = "[bench] strategy:  Medium / O(n√n)\n";
	c_text = "[bench] strategy:  Complex / O(n log n)\n";
	if (bench->strategy == STRATEGY_SIMPLE)
		write(2, s_text, ft_strlen(s_text));
	else if (bench->strategy == STRATEGY_MEDIUM)
		write(2, m_text, ft_strlen(m_text));
	else if (bench->strategy == STRATEGY_COMPLEX)
		write(2, c_text, ft_strlen(c_text));
	else
		print_adaptive(bench->disorder);
}
