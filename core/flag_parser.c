/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 13:15:57 by isabelle          #+#    #+#             */
/*   Updated: 2026/08/04 21:27:53 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

t_strategy	parse_strategy(char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0)
		return (STRATEGY_SIMPLE);
	if (ft_strcmp(arg, "--medium") == 0)
		return (STRATEGY_MEDIUM);
	if (ft_strcmp(arg, "--complex") == 0)
		return (STRATEGY_COMPLEX);
	if (ft_strcmp(arg, "--turk") == 0)
		return (STRATEGY_TURK);
	return (STRATEGY_ADAPTIVE);
}

int	is_strategy_flag(char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0)
		return (1);
	if (ft_strcmp(arg, "--medium") == 0)
		return (1);
	if (ft_strcmp(arg, "--complex") == 0)
		return (1);
	if (ft_strcmp(arg, "--turk") == 0)
		return (1);
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (1);
	return (0);
}
