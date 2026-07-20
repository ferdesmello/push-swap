/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_medium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 11:39:36 by isabelle          #+#    #+#             */
/*   Updated: 2026/07/20 03:54:28 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/* This function finds the node with the maximum index in the stack */
t_node	*find_max_index(t_stack *stack)
{
	t_node	*current;
	t_node	*max;

	if (!stack || !stack->head)
		return (NULL);
	current = stack->head;
	max = current;
	while (current)
	{
		if (current->index > max->index)
			max = current;
		current = current->next;
	}
	return (max);
}

/* This function pushes chunks of nodes from stack a to stack b */
static void	push_chunks_to_b(t_stack *a, t_stack *b, int chunk_size)
{
	int	pushed;

	pushed = 0;
	while (a->size > 0)
	{
		if (a->head->index <= pushed + chunk_size)
		{
			push_b(a, b);
			pushed++;
		}
		else
			rotate_a(a);
	}
}

/* This function pushes all nodes from stack b back to stack a 
in descending order */
static void	push_back_to_a(t_stack *a, t_stack *b)
{
	t_node	*max;
	int		position;

	while (b->size > 0)
	{
		max = find_max_index(b);
		position = find_position(b, max);
		move_to_top(b, position);
		push_a(b, a);
	}
}

/* This function sorts the stack using a medium algorithm */
void	medium_sort(t_stack *a, t_stack *b)
{
	int	chunk_size;

	assign_indexes(a);
	if (a->size <= 100)
		chunk_size = 20;
	else
		chunk_size = 45;
	push_chunks_to_b(a, b, chunk_size);
	push_back_to_a(a, b);
}
