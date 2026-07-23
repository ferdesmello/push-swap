/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 20:36:58 by ferde-so          #+#    #+#             */
/*   Updated: 2026/07/23 17:22:34 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function rotates the elements in a stack, 
moving the top element to the bottom */
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

/* This function rotates stack a */
void	rotate_a(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

/* This function rotates stack b */
void	rotate_b(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

/* This function rotates stack a and stack b */
void	rotate_ab(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
