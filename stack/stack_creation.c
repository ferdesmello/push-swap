/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 15:56:05 by iscarval          #+#    #+#             */
/*   Updated: 2026/07/28 20:12:23 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_init(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	stack->bench = NULL;
}

t_node	*node_new(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

int	stack_add_back(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node)
		return (0);
	if (!stack->head)
	{
		stack->head = new_node;
		stack->tail = new_node;
		stack->size = 1;
		return (1);
	}
	else
	{
		stack->tail->next = new_node;
		new_node->prev = stack->tail;
		stack->tail = new_node;
		stack->size++;
	}
	return (1);
}

int	stack_load(t_stack *a, int argc, char **argv, int start)
{
	int		i;
	long	value;
	t_node	*new;

	i = start;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (0);
		value = ft_atoi(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
			return (0);
		new = node_new((int)value);
		if (!new)
			return (0);
		if (!stack_add_back(a, new))
			return (0);
		i++;
	}
	if (!stack_repeated(a))
		return (0);
	return (1);
}

void	stack_clear(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}
