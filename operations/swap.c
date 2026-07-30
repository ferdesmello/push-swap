/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 20:35:46 by ferde-so          #+#    #+#             */
/*   Updated: 2026/07/30 04:39:38 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return ;
	first = stack->head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->head = second;
	if (stack->size == 2)
		stack->tail = first;
}

void	swap_a(t_stack *a)
{
	swap(a);
	if (a->config)
		bench_count(a->config, "sa");
	print_operation("sa\n");
}

void	swap_b(t_stack *b)
{
	swap(b);
	if (b->config)
		bench_count(b->config, "sb");
	print_operation("sb\n");
}

void	swap_ab(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	if (a->config)
		bench_count(a->config, "ss");
	print_operation("ss\n");
}
