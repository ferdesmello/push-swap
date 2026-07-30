/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 00:41:22 by ferde-so          #+#    #+#             */
/*   Updated: 2026/07/30 03:46:29 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_and_parse(t_stack *a, int argc, char **argv,
	t_bench *bench)
{
	int	start_index;

	start_index = 1;
	stack_init(a);
	if (start_index < argc
		&& ft_strcmp(argv[start_index], "--bench") == 0)
	{
		bench->bench_enabled = 1;
		start_index++;
	}
	if (start_index < argc && is_strategy_flag(argv[start_index]))
	{
		bench->strategy = parse_strategy(argv[start_index]);
		start_index++;
	}
	if (start_index == argc || !stack_load(a, argc, argv, start_index))
	{
		write(2, "Error\n", 6);
		stack_clear(a);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_bench		bench;

	bench_init(&bench);
	if (argc == 1)
		return (0);
	stack_init(&b);
	if (!init_and_parse(&a, argc, argv, &bench))
	{
		stack_clear(&b);
		return (0);
	}
	if (bench.bench_enabled)
	{
		a.bench = &bench;
		b.bench = &bench;
	}
	algo(&a, &b, bench.strategy);
	if (bench.bench_enabled)
		bench_print(&bench);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
