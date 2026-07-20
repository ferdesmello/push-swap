/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 20:35:46 by ferde-so          #+#    #+#             */
/*   Updated: 2026/07/20 05:16:49 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function swaps the first two nodes in a stack */
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

/* This function swaps the first two nodes in the stack a*/
void	swap_a(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
	(*a->operations)++;
}

/* This function swaps the first two nodes in the stack b*/
void	swap_b(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
	(*b->operations)++;
}

/* This function swaps the first two nodes in the stack a and b*/
void	swap_ab(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	(*a->operations)++;
}
