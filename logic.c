/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:00:52 by iscarval          #+#    #+#             */
/*   Updated: 2026/07/20 05:29:52 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function selects the best algorithm to sort the stack */
void	algo(t_stack *a, t_stack *b, t_strategy strategy)
{
	float	disorder;
	
	disorder = compute_disorder(a);
	ft_printf("Disorder: %f\n", disorder);
	if (is_sorted(a))
		return ;
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_small(a, b);
	else if (strategy == STRATEGY_SIMPLE)
		simple_sort(a, b);
	else if (strategy == STRATEGY_MEDIUM)
		medium_sort(a, b);
	//else if (strategy == STRATEGY_COMPLEX)
		//complex_sort(a, b);
	else if (strategy == STRATEGY_ADAPTIVE)
		adaptive_sort(a, b, disorder);
	else
		adaptive_sort(a, b, disorder);
	ft_printf("N operations: %d\n", (*a->operations));
}

/* This function selects the best algorithm 
based on the disorder of the stack */
void	adaptive_sort(t_stack *a, t_stack *b, float disorder)
{
	if (disorder < 0.2)
		simple_sort(a, b);
	else if (disorder >= 0.2 && disorder < 0.5)
		medium_sort(a, b);
	else
		medium_sort(a, b); // trocar para complex_sort quando feito
}
