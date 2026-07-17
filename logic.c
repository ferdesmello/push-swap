/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iscarval <iscarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:00:52 by iscarval          #+#    #+#             */
/*   Updated: 2026/07/16 21:06:31 by iscarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function selects the best algorithm to order the stack */
void	algo(t_stack *a, t_stack *b)
{
	(void)a;
	ft_printf("disorder: %f\n", compute_disorder(a));
	compute_disorder(b);
	if (a->size <= 1)
		return ;
	else if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
	//else
//{
	/* algoritmo grande */
//}
	stack_print(a, 'a', 1);
}
