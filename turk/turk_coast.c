/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_coast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 19:43:02 by isabelle          #+#    #+#             */
/*   Updated: 2026/08/04 21:17:06 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_move_cost(t_stack *stack, t_node *node)
{
	int	position;

	position = find_position(stack, node);
	if (position <= stack->size / 2)
		return (position);
	return (-(stack->size - position));
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	get_total_cost(t_stack *a, t_stack *b,
	t_node *node, t_node *target)
{
	int	cost_a;
	int	cost_b;

	cost_a = get_move_cost(a, node);
	cost_b = get_move_cost(b, target);
	if ((cost_a >= 0 && cost_b >= 0)
		|| (cost_a < 0 && cost_b < 0))
	{
		if (ft_abs(cost_a) > ft_abs(cost_b))
			return (ft_abs(cost_a));
		return (ft_abs(cost_b));
	}
	return (ft_abs(cost_a) + ft_abs(cost_b));
}

t_node	*find_cheapest(t_stack *a, t_stack *b)
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
		cost = get_total_cost(a, b, current, target);
		if (!cheapest || cost < best_cost)
		{
			cheapest = current;
			best_cost = cost;
		}
		current = current->next;
	}
	return (cheapest);
}
