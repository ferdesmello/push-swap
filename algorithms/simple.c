/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 17:44:54 by iscarval          #+#    #+#             */
/*   Updated: 2026/07/28 20:10:44 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*find_max(t_stack *stack)
{
	t_node	*current;
	t_node	*max;

	if (!stack || !stack->head)
		return (NULL);
	max = stack->head;
	current = stack->head->next;
	while (current)
	{
		if (current->value > max->value)
			max = current;
		current = current->next;
	}
	return (max);
}

t_node	*find_min(t_stack *stack)
{
	t_node	*current;
	t_node	*min;

	if (!stack || !stack->head)
		return (NULL);
	min = stack->head;
	current = stack->head->next;
	while (current)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}

int	find_position(t_stack *stack, t_node *node)
{
	t_node	*current;
	int		position;

	if (!stack || !stack->head || !node)
		return (-1);
	current = stack->head;
	position = 0;
	while (current)
	{
		if (current == node)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

void	move_to_top(t_stack *stack, int position, char name)
{
	int	moves;

	if (position <= stack->size / 2)
	{
		moves = position;
		while (moves-- > 0)
		{
			if (name == 'a')
				rotate_a(stack);
			else
				rotate_b(stack);
		}
	}
	else
	{
		moves = stack->size - position;
		while (moves-- > 0)
		{
			if (name == 'a')
				reverse_rotate_a(stack);
			else
				reverse_rotate_b(stack);
		}
	}
}

void	simple_sort(t_stack *a, t_stack *b)
{
	t_node	*min;
	int		position;

	while (a->size > 0)
	{
		min = find_min(a);
		position = find_position(a, min);
		move_to_top(a, position, 'a');
		push_b(a, b);
	}
	while (b->size > 0)
		push_a(b, a);
}
