/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 11:39:36 by isabelle          #+#    #+#             */
/*   Updated: 2026/07/26 19:55:07 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* This function assigns indexes to the nodes in the stack */
void	assign_indexes(t_stack *a)
{
	t_node	*current;
	t_node	*compare;

	current = a->head;
	while (current)
	{
		current->index = 0;
		compare = a->head;
		while (compare)
		{
			if (compare->value < current->value)
				current->index++;
			compare = compare->next;
		}
		current = current->next;
	}
}

/*  This function finds the position (from the top or bottom) 
of the first node in the stack that has an index less than or
 equal to the limit */
int	find_chunk_position(t_stack *a, int limit)
{
	t_node	*top;
	t_node	*bottom;
	int		top_position;
	int		bottom_position;

	top = a->head;
	bottom = a->tail;
	top_position = 0;
	bottom_position = a->size - 1;
	while (top && bottom)
	{
		if (top->index <= limit)
			return (top_position);
		if (bottom->index <= limit)
			return (bottom_position);
		top = top->next;
		bottom = bottom->prev;
		top_position++;
		bottom_position--;
	}
	return (-1);
}

/* This function pushes chunks of nodes from stack a to stack b */
static void	push_chunks_to_b(t_stack *a, t_stack *b, int chunk_size)
{
	int	pushed;
	int	position;

	pushed = 0;
	while (a->size > 0)
	{
		position = find_chunk_position(a, pushed + chunk_size);
		move_to_top(a, position, 'a');
		push_b(a, b);
		if (b->head->index < pushed + (chunk_size / 2))
			rotate_b(b);
		pushed++;
	}
}

/* This function pushes all nodes from stack b back to stack a 
in descending order */
static void	push_back_to_a(t_stack *a, t_stack *b)
{
	t_node	*current;
	int		position;

	while (b->size > 0)
	{
		current = b->head;
		position = 0;
		while (current)
		{
			if (current->index == b->size - 1)
				break ;
			current = current->next;
			position++;
		}
		move_to_top(b, position, 'b');
		push_a(b, a);
	}
}

/* This function sorts the stack using a medium complexity algorithm */
void	medium_sort(t_stack *a, t_stack *b)
{
	int	chunk_size;

	if (a->size <= 100)
		chunk_size = 20;
	else
		chunk_size = 45;
	push_chunks_to_b(a, b, chunk_size);
	push_back_to_a(a, b);
}
