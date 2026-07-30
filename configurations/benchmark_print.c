/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:59:19 by isabelle          #+#    #+#             */
/*   Updated: 2026/07/30 04:15:20 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	putnbr_stderr(int n)
{
	char	c;

	if (n > 9)
		putnbr_stderr(n / 10);
	c = (n % 10) + '0';
	write(2, &c, 1);
}

static void	print_op(char *name, int len, int count)
{
	write(2, name, len);
	write(2, ":  ", 3);
	putnbr_stderr(count);
	if (!(name[0] == 'p' && name[1] == 'b'))
		if (!(name[0] == 'r' && name[1] == 'r' && name[2] == 'r'))
			write(2, "  ", 2);
}

static void	bench_print_total(t_config *config)
{
	write(2, "[bench] total_ops:  ", 20);
	putnbr_stderr(print_total(config));
	write(2, "\n", 1);
}

static void	bench_print_ops(t_config *config)
{
	write(2, "[bench] ", 8);
	print_op("sa", 2, config->sa);
	print_op("sb", 2, config->sb);
	print_op("ss", 2, config->ss);
	print_op("pa", 2, config->pa);
	print_op("pb", 2, config->pb);
	write(2, "\n", 1);
	write(2, "[bench] ", 8);
	print_op("ra", 2, config->ra);
	print_op("rb", 2, config->rb);
	print_op("rr", 2, config->rr);
	print_op("rra", 3, config->rra);
	print_op("rrb", 3, config->rrb);
	print_op("rrr", 3, config->rrr);
	write(2, "\n", 1);
}

void	bench_print(t_config *config)
{
	int	percent;

	percent = (int)(config->disorder * 10000 + 0.5);
	write(2, "[bench] disorder:  ", 19);
	putnbr_stderr(percent / 100);
	write(2, ".", 1);
	if (percent % 100 < 10)
		write(2, "0", 1);
	putnbr_stderr(percent % 100);
	write(2, "%\n", 2);
	bench_print_strategy(config);
	bench_print_total(config);
	bench_print_ops(config);
}
