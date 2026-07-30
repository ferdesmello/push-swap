/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <isabelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 01:02:30 by isabelle          #+#    #+#             */
/*   Updated: 2026/07/30 01:10:18 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_operation(char *operation)
{
	int	i;

	i = 0;
	while (operation[i])
		i++;
	write(1, operation, i);
}
