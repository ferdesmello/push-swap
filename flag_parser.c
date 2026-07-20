/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 13:15:57 by isabelle          #+#    #+#             */
/*   Updated: 2026/07/20 03:33:44 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function compares two string */
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* This function parses the strategy flag from the command line argument */
t_strategy	parse_strategy(char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0)
		return (STRATEGY_SIMPLE);
	if (ft_strcmp(arg, "--medium") == 0)
		return (STRATEGY_MEDIUM);
	if (ft_strcmp(arg, "--complex") == 0)
		return (STRATEGY_COMPLEX);
	return (STRATEGY_ADAPTIVE);
}

/* This function checks if the given argument is a strategy flag */
int	is_strategy_flag(char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0)
		return (1);
	if (ft_strcmp(arg, "--medium") == 0)
		return (1);
	if (ft_strcmp(arg, "--complex") == 0)
		return (1);
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (1);
	return (0);
}
