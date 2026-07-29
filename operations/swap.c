/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 20:35:46 by ferde-so          #+#    #+#             */
/*   Updated: 2026/07/29 00:00:08 by ferde-so         ###   ########.fr       */
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
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *b)
{
	swap(b);
	if (b->bench)
		bench_count(b->bench, "sb");
	write(1, "sb\n", 3);
}

void	swap_ab(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	if (a->bench)
		bench_count(a->bench, "ss");
	write(1, "ss\n", 3);
}
