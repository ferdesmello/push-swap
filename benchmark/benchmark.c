/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 05:04:54 by isabelle          #+#    #+#             */
/*   Updated: 2026/07/30 03:44:45 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bench_init(t_bench *bench)
{
	bench->strategy = STRATEGY_ADAPTIVE;
	bench->bench_enabled = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->disorder = 0.0;
	
}

void	bench_count(t_bench *bench, char *op)
{
	if (ft_strcmp(op, "sa") == 0)
		bench->sa++;
	else if (ft_strcmp(op, "sb") == 0)
		bench->sb++;
	else if (ft_strcmp(op, "ss") == 0)
		bench->ss++;
	else if (ft_strcmp(op, "pa") == 0)
		bench->pa++;
	else if (ft_strcmp(op, "pb") == 0)
		bench->pb++;
}

void	bench_count_rotate(t_bench *bench, char *op)
{
	if (ft_strcmp(op, "ra") == 0)
		bench->ra++;
	else if (ft_strcmp(op, "rb") == 0)
		bench->rb++;
	else if (ft_strcmp(op, "rr") == 0)
		bench->rr++;
}

void	bench_count_reverse(t_bench *bench, char *op)
{
	if (ft_strcmp(op, "rra") == 0)
		bench->rra++;
	else if (ft_strcmp(op, "rrb") == 0)
		bench->rrb++;
	else if (ft_strcmp(op, "rrr") == 0)
		bench->rrr++;
}

int	bench_total(t_bench *bench)
{
	return (bench->sa + bench->sb + bench->ss
		+ bench->pa + bench->pb + bench->ra
		+ bench->rb + bench->rr + bench->rra
		+ bench->rrb + bench->rrr);
}
