/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 01:05:17 by ferde-so          #+#    #+#             */
/*   Updated: 2026/07/10 01:05:35 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void print_test(t_stack *stack)
{
	t_node *current;
	current = stack->head;
	while (current != NULL)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}
