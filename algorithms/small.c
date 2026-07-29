/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:40:14 by iscarval          #+#    #+#             */
/*   Updated: 2026/07/28 20:10:53 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_min_to_b(t_stack *a, t_stack *b)
{
	t_node	*min;
	int		position;

	min = find_min(a);
	position = find_position(a, min);
	move_to_top(a, position, 'a');
	push_b(a, b);
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
