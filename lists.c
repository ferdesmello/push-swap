/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 00:41:47 by ferde-so          #+#    #+#             */
/*   Updated: 2026/07/10 01:06:50 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void stack_init(t_stack *stack)
{
	stack->head = NULL; 
	stack->tail = NULL; 
	stack->size = 0; 
} 
t_node *node_new(int value) 
{ 
	t_node *new_node; 
	new_node = malloc(sizeof(t_node)); 
	if (new_node == 0) return (0); 
	new_node->value = value; 
	new_node->next = NULL; 
	return (new_node); 
} 

void stack_add_back(t_stack *stack, t_node *new_node)
{ 
	if (!stack || !new_node)
		return ; 
	if (!stack->head)
	{ 
		stack->head = new_node; 
		stack->tail = new_node; 
		stack->size = 1; 
		return ; 
	} 
	else
	{ 
		stack->tail->next = new_node; 
		new_node->prev = stack->tail; 
		stack->tail = new_node; 
		stack->size++; 
	}
} 

void ft_lstclear(t_node **stack, void (*del)(int)) { 
	t_node *current; 
	t_node *next_node; 
	if (stack == 0 || *stack == 0 || del == 0) return ; 
	current = *stack; 
	while (current != 0) { 
		next_node = current->next; 
		del(current->value); 
		free(current); 
		current = next_node; 
	} 
	*stack = NULL; 
}
