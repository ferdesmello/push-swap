/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 20:17:08 by iscarval          #+#    #+#             */
/*   Updated: 2026/08/04 21:19:44 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*find_target_a(t_stack *a, t_node *node)
{
	t_node	*current;
	t_node	*target;

	target = NULL;
	current = a->head;
	while (current)
	{
		if (current->value > node->value
			&& (!target || current->value < target->value))
			target = current;
		current = current->next;
	}
	if (!target)
		target = find_min(a);
	return (target);
}

static void	push_back_to_a(t_stack *a, t_stack *b)
{
	t_node	*target;

	while (b->size > 0)
	{
		target = find_target_a(a, b->head);
		move_to_top(a, find_position(a, target), 'a');
		push_a(b, a);
	}
}

void	turk_sort(t_stack *a, t_stack *b)
{
	t_node	*min;

	push_to_b(a, b);
	push_back_to_a(a, b);
	min = find_min(a);
	move_to_top(a, find_position(a, min), 'a');
}
