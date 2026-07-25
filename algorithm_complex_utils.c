/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_turk_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <isabelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 20:17:08 by isabelle          #+#    #+#             */
/*   Updated: 2026/07/22 21:39:40 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_target_b(t_stack *b, t_node *node)
{
	t_node	*current;
	t_node	*target;

	target = NULL;
	current = b->head;
	while (current)
	{
		if (current->value < node->value
			&& (!target || current->value > target->value))
			target = current;
		current = current->next;
	}
	if (!target)
		target = find_max(b);
	return (target);
}

static int	get_move_cost(t_stack *stack, t_node *node)
{
	int	position;

	position = find_position(stack, node);
	if (position <= stack->size / 2)
		return (position);
	return (stack->size - position);
}

static t_node	*find_cheapest(t_stack *a, t_stack *b)
{
	t_node	*current;
	t_node	*cheapest;
	t_node	*target;
	int		cost;
	int		best_cost;

	current = a->head;
	cheapest = NULL;
	while (current)
	{
		target = find_target_b(b, current);
		cost = get_move_cost(a, current)
			+ get_move_cost(b, target);
		if (!cheapest || cost < best_cost)
		{
			cheapest = current;
			best_cost = cost;
		}
		current = current->next;
	}
	return (cheapest);
}

static void	move_cheapest(t_stack *a, t_stack *b)
{
	t_node	*cheapest;
	t_node	*target;

	cheapest = find_cheapest(a, b);
	target = find_target_b(b, cheapest);
	move_to_top(a, find_position(a, cheapest), 'a');
	move_to_top(b, find_position(b, target), 'b');
	push_b(a, b);
}

void	push_to_b(t_stack *a, t_stack *b)
{
	push_b(a, b);
	push_b(a, b);
	while (a->size > 3)
		move_cheapest(a, b);
	sort_three(a);
}
