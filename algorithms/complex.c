/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 20:17:08 by iscarval          #+#    #+#             */
/*   Updated: 2026/07/26 20:01:32 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_max_bits(t_stack *a)
{
	int	max_index;
	int	max_bits;

	max_index = a->size - 1;
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	complex_sort(t_stack *a, t_stack *b)
{
	int	bit;
	int	max_bits;
	int	size;
	int	i;

	max_bits = get_max_bits(a);
	bit = 0;
	while (bit < max_bits)
	{
		size = a->size;
		i = 0;
		while (i < size)
		{
			if (((a->head->index >> bit) & 1) == 0)
				push_b(a, b);
			else
				rotate_a(a);
			i++;
		}
		while (b->size > 0)
			push_a(b, a);
		bit++;
	}
}
