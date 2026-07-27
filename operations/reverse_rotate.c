/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 20:36:53 by ferde-so          #+#    #+#             */
/*   Updated: 2026/07/26 19:54:47 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* This function reverse rotates the elements in a stack, 
moving the bottom element to the top */
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

/* This function reverse rotates stack a */
void	reverse_rotate_a(t_stack *a)
{
	reverse_rotate(a);
	if (a->bench)
		bench_count_reverse(a->bench, "rra");
	write(1, "rra\n", 4);
}

/* This function reverse rotates stack b */
void	reverse_rotate_b(t_stack *b)
{
	reverse_rotate(b);
	if (b->bench)
		bench_count_reverse(b->bench, "rrb");
	write(1, "rrb\n", 4);
}

/* This function reverse rotates stack a and stack b */
void	reverse_rotate_ab(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (a->bench)
		bench_count_reverse(a->bench, "rrr");
	write(1, "rrr\n", 4);
}
