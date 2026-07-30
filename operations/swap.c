/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <isabelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 20:35:46 by ferde-so          #+#    #+#             */
/*   Updated: 2026/07/30 01:24:36 by isabelle         ###   ########.fr       */
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
	if (a->bench)
		bench_count(a->bench, "sa");
	print_operation("sa\n");
}

void	swap_b(t_stack *b)
{
	swap(b);
	if (b->bench)
		bench_count(b->bench, "sb");
	print_operation("sb\n");
}

void	swap_ab(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	if (a->bench)
		bench_count(a->bench, "ss");
	print_operation("ss\n");
}
