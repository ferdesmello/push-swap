/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 01:02:30 by isabelle          #+#    #+#             */
/*   Updated: 2026/07/30 22:05:12 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_operation(char *operation, t_stack *a)
{
	int		i;

	if (a->config)
	{
		bench_count(a->config, operation);
		i = 0;
		while (operation[i] != '\0')
		{
			write(1, &operation[i], 1);
			i++;
		}
		write(1, "\n", 1);
	}		
}
