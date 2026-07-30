/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <isabelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 20:36:58 by ferde-so          #+#    #+#             */
/*   Updated: 2026/07/30 01:23:45 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*node;

	if (!stack->head || !stack->head->next)
		return ;
	node = stack->head;
	stack->head = node->next;
	stack->head->prev = NULL;
	stack->tail->next = node;
	node->prev = stack->tail;
	stack->tail = node;
	node->next = NULL;
}

void	rotate_a(t_stack *a)
{
	rotate(a);
	if (a->bench)
		bench_count_rotate(a->bench, "ra");
	print_operation("ra\n");
}

void	rotate_b(t_stack *b)
{
	rotate(b);
	if (b->bench)
		bench_count_rotate(b->bench, "rb");
	print_operation("rb\n");
}

void	rotate_ab(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	if (a->bench)
		bench_count_rotate(a->bench, "rr");
	print_operation("rr\n");
}
