/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_strategy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 15:28:26 by isabelle          #+#    #+#             */
/*   Updated: 2026/07/26 19:54:30 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_adaptive(float disorder)
{
	if (disorder < 0.2)
		write(2, "[bench] strategy: adaptive -> simple / O(n^2)\n", 47);
	else if (disorder < 0.5)
		write(2, "[bench] strategy: adaptive -> medium / O(n*sqrt(n))\n",
			52);
	else
		write(2, "[bench] strategy: adaptive -> complex / O(n log n)\n",
			51);
}

void	bench_print_strategy(t_bench *bench)
{
	if (bench->strategy == STRATEGY_SIMPLE)
		write(2, "[bench] strategy: simple / O(n^2)\n", 35);
	else if (bench->strategy == STRATEGY_MEDIUM)
		write(2, "[bench] strategy: medium / O(n*sqrt(n))\n", 40);
	else if (bench->strategy == STRATEGY_COMPLEX)
		write(2, "[bench] strategy: complex / O(n log n)\n", 39);
	else
		print_adaptive(bench->disorder);
}
