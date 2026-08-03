/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 05:04:54 by isabelle          #+#    #+#             */
/*   Updated: 2026/08/03 06:50:55 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	config_init(t_config *config)
{
	config->strategy = STRATEGY_ADAPTIVE;
	config->bench_enabled = 0;
	config->sa = 0;
	config->sb = 0;
	config->ss = 0;
	config->pa = 0;
	config->pb = 0;
	config->ra = 0;
	config->rb = 0;
	config->rr = 0;
	config->rra = 0;
	config->rrb = 0;
	config->rrr = 0;
	config->disorder = 0.0;
}

void	bench_count(t_config *config, char *op)
{
	if (ft_strcmp(op, "sa") == 0)
		config->sa++;
	else if (ft_strcmp(op, "sb") == 0)
		config->sb++;
	else if (ft_strcmp(op, "ss") == 0)
		config->ss++;
	else if (ft_strcmp(op, "pa") == 0)
		config->pa++;
	else if (ft_strcmp(op, "pb") == 0)
		config->pb++;
	else if (ft_strcmp(op, "ra") == 0)
		config->ra++;
	else if (ft_strcmp(op, "rb") == 0)
		config->rb++;
	else if (ft_strcmp(op, "rr") == 0)
		config->rr++;
	else if (ft_strcmp(op, "rra") == 0)
		config->rra++;
	else if (ft_strcmp(op, "rrb") == 0)
		config->rrb++;
	else if (ft_strcmp(op, "rrr") == 0)
		config->rrr++;
}

int	print_total(t_config *config)
{
	return (config->sa + config->sb + config->ss
		+ config->pa + config->pb + config->ra
		+ config->rb + config->rr + config->rra
		+ config->rrb + config->rrr);
}
