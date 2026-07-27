/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 00:28:34 by ferde-so          #+#    #+#             */
/*   Updated: 2026/07/26 19:54:38 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* This function prints the values in a stack in order and reverse order 
(double directions in links) to check if they are correct. The flag parameter
determines the order of printing. 1 for forward, 2 for reverse, 3 for both */
void	stack_print(t_stack *stack, char name, int flag)
{
	t_node	*current;

	if (flag == 1 || flag == 3)
	{
		current = stack->head;
		ft_printf("stack %c: ", name);
		while (current != NULL)
		{
			ft_printf("%d ", current->value);
			current = current->next;
		}
		ft_printf("\n");
	}
	if (flag == 2 || flag == 3)
	{
		current = stack->tail;
		ft_printf("stack %c: ", name);
		while (current != NULL)
		{
			ft_printf("%d ", current->value);
			current = current->prev;
		}
		ft_printf("\n");
	}
}

/* This function checks if a stack has valid links and is valid */
int	stack_valid(t_stack *stack)
{
	int		count;
	t_node	*current;

	if (!stack->head && (stack->tail || stack->size != 0))
		return (0);
	if (!stack->tail && (stack->head || stack->size != 0))
		return (0);
	if ((stack->head && stack->head->prev)
		|| (stack->tail && stack->tail->next))
		return (0);
	count = 0;
	current = stack->head;
	while (current)
	{
		if (current->next && current->next->prev != current)
			return (0);
		if (current->prev && current->prev->next != current)
			return (0);
		count++;
		current = current->next;
	}
	if (count != stack->size)
		return (0);
	count = 0;
	current = stack->tail;
	while (current)
	{
		count++;
		current = current->prev;
	}
	if (count != stack->size)
		return (0);
	return (1);
}

/* This function operates on the stacks to test if the push-swap-rotate 
functions are working correctly and the resulting stacks are valid */
int	stack_operations_test(t_stack *a, t_stack *b)
{
	//initial state of stacks
	stack_print(a, 'a', 1);
	stack_print(b, 'b', 1);

	//rotates and reverse rotates a twice
	rotate_a(a);
	if (!stack_valid(a))
		return (0);
	stack_print(a, 'a', 1);
	stack_print(b, 'b', 1);
	reverse_rotate_a(a);
	if (!stack_valid(a))
		return (0);
	stack_print(a, 'a', 1);
	stack_print(b, 'b', 1);

	//swaps a twice
	swap_a(a);
	if (!stack_valid(a))
		return (0);
	stack_print(a, 'a', 1);
	stack_print(b, 'b', 1);
	swap_a(a);
	if (!stack_valid(a))
		return (0);
	stack_print(a, 'a', 1);
	stack_print(b, 'b', 1);

	//pushes a to b 4 times
	push_b(a, b);
	if (!stack_valid(a))
		return (0);
	push_b(a, b);
	if (!stack_valid(a))
		return (0);
	push_b(a, b);
	if (!stack_valid(a))
		return (0);
	push_b(a, b);
	if (!stack_valid(a))
		return (0);
	stack_print(a, 'a', 1);
	stack_print(b, 'b', 1);

	//rotates b twice
	rotate_b(b);
	if (!stack_valid(b))
		return (0);
	stack_print(a, 'a', 1);
	stack_print(b, 'b', 1);
	reverse_rotate_b(b);
	if (!stack_valid(b))
		return (0);
	stack_print(a, 'a', 1);
	stack_print(b, 'b', 1);

	//swaps b twice
	swap_b(b);
	if (!stack_valid(b))
		return (0);
	stack_print(a, 'a', 1);
	stack_print(b, 'b', 1);
	swap_b(b);
	if (!stack_valid(b))
		return (0);
	stack_print(a, 'a', 1);
	stack_print(b, 'b', 1);

	//swaps both twice
	swap_ab(a, b);
	if (!stack_valid(a))
		return (0);
	if (!stack_valid(b))
		return (0);
	stack_print(a, 'a', 1);
	stack_print(b, 'b', 1);
	swap_ab(a, b);
	if (!stack_valid(a))
		return (0);
	if (!stack_valid(b))
		return (0);
	stack_print(a, 'a', 1);
	stack_print(b, 'b', 1);

	//rotates and reverse rotates both
	rotate_ab(a, b);
	if (!stack_valid(a))
		return (0);
	if (!stack_valid(b))
		return (0);
	stack_print(a, 'a', 1);
	stack_print(b, 'b', 1);
	reverse_rotate_ab(a, b);
	if (!stack_valid(a))
		return (0);
	if (!stack_valid(b))
		return (0);
	stack_print(a, 'a', 1);
	stack_print(b, 'b', 1);

	//pushes b to a 4 times
	push_a(b, a);
	if (!stack_valid(a))
		return (0);
	if (!stack_valid(b))
		return (0);
	push_a(b, a);
	if (!stack_valid(a))
		return (0);
	if (!stack_valid(b))
		return (0);
	push_a(b, a);
	if (!stack_valid(a))
		return (0);
	if (!stack_valid(b))
		return (0);
	push_a(b, a);
	if (!stack_valid(a))
		return (0);
	if (!stack_valid(b))
		return (0);
	stack_print(a, 'a', 1);
	stack_print(b, 'b', 1);

	return (1);
}
