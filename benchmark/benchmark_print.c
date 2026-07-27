/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:59:19 by isabelle          #+#    #+#             */
/*   Updated: 2026/07/26 19:54:32 by ferde-so         ###   ########.fr       */
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
	write(2, "[bench] ", 8);
	write(2, name, len);
	write(2, ": ", 2);
	putnbr_stderr(count);
	write(2, "\n", 1);
}

static void	bench_print_total(t_bench *bench)
{
	write(2, "[bench] total_ops: ", 19);
	putnbr_stderr(bench_total(bench));
	write(2, "\n", 1);
}

static void	bench_print_ops(t_bench *bench)
{
	print_op("sa", 2, bench->sa);
	print_op("sb", 2, bench->sb);
	print_op("ss", 2, bench->ss);
	print_op("pa", 2, bench->pa);
	print_op("pb", 2, bench->pb);
	print_op("ra", 2, bench->ra);
	print_op("rb", 2, bench->rb);
	print_op("rr", 2, bench->rr);
	print_op("rra", 3, bench->rra);
	print_op("rrb", 3, bench->rrb);
	print_op("rrr", 3, bench->rrr);
}

void	bench_print(t_bench *bench)
{
	int	percent;

	percent = (int)(bench->disorder * 10000 + 0.5);
	write(2, "[bench] disorder: ", 18);
	putnbr_stderr(percent / 100);
	write(2, ".", 1);
	if (percent % 100 < 10)
		write(2, "0", 1);
	putnbr_stderr(percent % 100);
	write(2, "%\n", 2);
	bench_print_strategy(bench);
	bench_print_total(bench);
	bench_print_ops(bench);
}
