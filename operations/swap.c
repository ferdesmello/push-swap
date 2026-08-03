/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 20:35:46 by ferde-so          #+#    #+#             */
/*   Updated: 2026/08/03 06:35:16 by ferde-so         ###   ########.fr       */
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
	print_operation("sa", a);
}

void	swap_b(t_stack *b)
{
	swap(b);
	print_operation("sb", b);
}

void	swap_ab(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	print_operation("ss", a);
}
