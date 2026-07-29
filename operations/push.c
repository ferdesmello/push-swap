/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 20:36:19 by ferde-so          #+#    #+#             */
/*   Updated: 2026/07/28 23:59:43 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack *src, t_stack *dst)
{
	t_node	*node;

	if (!src->head)
		return ;
	node = src->head;
	src->head = node->next;
	if (src->head)
		src->head->prev = NULL;
	else
		src->tail = NULL;
	node->next = dst->head;
	node->prev = NULL;
	if (dst->head)
		dst->head->prev = node;
	dst->head = node;
	if (!dst->tail)
		dst->tail = node;
	dst->size++;
	src->size--;
}

void	push_a(t_stack *b, t_stack *a)
{
	push(b, a);
	if (a->bench)
		bench_count(a->bench, "pa");
	write(1, "pa\n", 3);
}

void	push_b(t_stack *a, t_stack *b)
{
	push(a, b);
	if (a->bench)
		bench_count(a->bench, "pb");
	write(1, "pb\n", 3);
}
