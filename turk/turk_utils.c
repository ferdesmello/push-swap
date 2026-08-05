/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 20:17:08 by isabelle          #+#    #+#             */
/*   Updated: 2026/08/04 21:18:54 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static void	move_both(t_stack *a, t_stack *b,
	int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rotate_ab(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		reverse_rotate_ab(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	move_remaining(t_stack *stack, int cost, char name)
{
	while (cost > 0)
	{
		if (name == 'a')
			rotate_a(stack);
		else
			rotate_b(stack);
		cost--;
	}
	while (cost < 0)
	{
		if (name == 'a')
			reverse_rotate_a(stack);
		else
			reverse_rotate_b(stack);
		cost++;
	}
}

static void	move_cheapest(t_stack *a, t_stack *b)
{
	t_node	*cheapest;
	t_node	*target;
	int		cost_a;
	int		cost_b;

	cheapest = find_cheapest(a, b);
	target = find_target_b(b, cheapest);
	cost_a = get_move_cost(a, cheapest);
	cost_b = get_move_cost(b, target);
	move_both(a, b, &cost_a, &cost_b);
	move_remaining(a, cost_a, 'a');
	move_remaining(b, cost_b, 'b');
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
