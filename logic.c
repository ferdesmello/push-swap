/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 00:43:18 by ferde-so          #+#    #+#             */
/*   Updated: 2026/07/10 01:05:29 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int logic(int argc, char **argv)
{
	int i; 
	int value; 
	t_stack a; 
	t_stack b; 
	t_node *new;
	
	stack_init(&a);
	stack_init(&b); 
	i = 1;
	while (i < argc)
	{
		if (!isnumber(argv[i]))
			return (0);
		value = ft_atoi(argv[i]);
		new = node_new(value);
		if (!new)
			return (0);
		stack_add_back(&a, new);
		i++;
	}
	print_test(&a);
	return (1); 
}
