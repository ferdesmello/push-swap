/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:40:14 by iscarval          #+#    #+#             */
/*   Updated: 2026/08/03 06:50:05 by ferde-so         ###   ########.fr       */
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

static int	push_min_to_b(t_stack *a, t_stack *b)
{
	t_node	*min;
	int		position;

	min = find_min(a);
	position = find_position(a, min);
	move_to_top(a, position, 'a');
	push_b(a, b);
	return (1);
}

void	sort_two(t_stack *a)
{
	if (a->head->value > a->head->next->value)
		swap_a(a);
}

void	sort_three(t_stack *a)
{
	t_node	*max;
	int		position;

	max = find_max(a);
	position = find_position(a, max);
	if (position == 0)
		rotate_a(a);
	else if (position == 1)
		reverse_rotate_a(a);
	if (a->head->value > a->head->next->value)
		swap_a(a);
}

void	sort_small(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		push_min_to_b(a, b);
	sort_three(a);
	while (b->size > 0)
		push_a(b, a);
}
