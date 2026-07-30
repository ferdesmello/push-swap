/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 00:41:22 by ferde-so          #+#    #+#             */
/*   Updated: 2026/07/30 04:38:17 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_and_parse(t_stack *a, int argc, char **argv,
	t_config *config)
{
	int	start_index;

	start_index = 1;
	stack_init(a);
	if (start_index < argc
		&& ft_strcmp(argv[start_index], "--bench") == 0)
	{
		config->bench_enabled = 1;
		start_index++;
	}
	if (start_index < argc && is_strategy_flag(argv[start_index]))
	{
		config->strategy = parse_strategy(argv[start_index]);
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
	t_config	config;

	config_init(&config);
	if (argc == 1)
		return (0);
	stack_init(&b);
	if (!init_and_parse(&a, argc, argv, &config))
	{
		stack_clear(&b);
		return (0);
	}
	a.config = &config;
	b.config = &config;
	algo(&a, &b, config.strategy);
	if (config.bench_enabled)
		bench_print(&config);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
