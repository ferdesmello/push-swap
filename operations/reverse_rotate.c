/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <isabelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 20:36:53 by ferde-so          #+#    #+#             */
/*   Updated: 2026/07/30 01:22:51 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*node;

	if (!stack->tail || !stack->tail->prev)
		return ;
	node = stack->tail;
	stack->tail = node->prev;
	stack->tail->next = NULL;
	node->prev = NULL;
	node->next = stack->head;
	stack->head->prev = node;
	stack->head = node;
}

void	reverse_rotate_a(t_stack *a)
{
	reverse_rotate(a);
	if (a->bench)
		bench_count_reverse(a->bench, "rra");
	print_operation("rra\n");
}

void	reverse_rotate_b(t_stack *b)
{
	reverse_rotate(b);
	if (b->bench)
		bench_count_reverse(b->bench, "rrb");
	print_operation("rrb\n");
}

void	reverse_rotate_ab(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (a->bench)
		bench_count_reverse(a->bench, "rrr");
	print_operation("rrr\n");
}
