/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iscarval <iscarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 00:41:22 by ferde-so          #+#    #+#             */
/*   Updated: 2026/07/16 20:56:45 by iscarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function gets the arguments and creates the stacks */
int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	stack_init(&a);
	stack_init(&b);
	if (argc == 1)
	{
		write(1, "Error1\n", 7);
		return (0);
	}
	if (!stack_load(&a, argc, argv))
	{
		write(1, "Error2\n", 7);
		stack_clear(&a);
		stack_clear(&b);
		return (0);
	}
	algo(&a, &b);
	// stack_operations_test(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
