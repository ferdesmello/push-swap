/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 00:41:22 by ferde-so          #+#    #+#             */
/*   Updated: 2026/07/23 17:41:29 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Helper function to handle input parsing and validation */
static int	init_and_parse(t_stack *a, int argc, char **argv, t_strategy *strat)
{
	int	start_index;

	start_index = 1;
	stack_init(a);
	if (start_index < argc && is_strategy_flag(argv[start_index]))
	{
		*strat = parse_strategy(argv[start_index]);
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

/* This function gets the arguments and creates the stacks */
int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_strategy	strategy;

	strategy = STRATEGY_ADAPTIVE;
	if (argc == 1)
		return (0);
	stack_init(&b);
	if (!init_and_parse(&a, argc, argv, &strategy))
	{
		stack_clear(&b);
		return (0);
	}
	algo(&a, &b, strategy);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
