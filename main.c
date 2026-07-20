/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 00:41:22 by ferde-so          #+#    #+#             */
/*   Updated: 2026/07/20 05:13:56 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function gets the arguments and creates the stacks */
int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_strategy	strategy;
	int			start_index;
	int operations = 0;

	stack_init(&a);
	stack_init(&b);
	a.operations = &operations;
	b.operations = &operations;
	strategy = STRATEGY_ADAPTIVE;
	if (argc == 1)
		return (0);
	start_index = 1;
	if (start_index < argc && is_strategy_flag(argv[start_index]))
	{
		strategy = parse_strategy(argv[start_index]);
		start_index++;
	}
	if (start_index == argc)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!stack_load(&a, argc, argv, start_index))
	{
		write(2, "Error\n", 6);
		stack_clear(&a);
		stack_clear(&b);
		return (0);
	}
	algo(&a, &b, strategy);
	// stack_operations_test(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
