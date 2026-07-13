/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 15:56:19 by iscarval          #+#    #+#             */
/*   Updated: 2026/07/13 18:11:40 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function checks if a string represents a valid number */
int	is_number(const char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!ft_is_digit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

/* This function checks if a character is a digit */
int	ft_is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/* This function converts a string to an integer */
int	ft_atoi(const char *nptr)
{
	int	number;
	int	i;
	int	sign;

	number = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + (nptr[i] - '0');
		i++;
	}
	number = number * sign;
	return (number);
}

/* This function calculates the disorder of the a stack given */
float	compute_disorder(t_stack *a)
{
	float	mistakes;
	float	total_pairs;
	t_node	*node_i;
	t_node	*node_j;

	if (!a || !a->head || !a->head->next)
		return (0.0);
	mistakes = 0.0;
	total_pairs = 0.0;
	node_i = a->head;
	while (node_i != NULL)
	{
		node_j = node_i->next;
		while (node_j != NULL)
		{
			total_pairs++;
			if (node_i->value > node_j->value)
				mistakes++;
			node_j = node_j->next;
		}
		node_i = node_i->next;
	}
	if (total_pairs == 0.0)
		return (0.0);
	return (mistakes / total_pairs);
}
