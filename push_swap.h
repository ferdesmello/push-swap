/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 14:27:15 by iscarval          #+#    #+#             */
/*   Updated: 2026/07/30 22:04:47 by ferde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;


typedef enum e_strategy
{
	STRATEGY_ADAPTIVE,
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX,
}	t_strategy;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench_enabled;
	int			sa;
	int			sb;
	int			ss;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
	float		disorder;
}	t_config;

typedef struct s_stack
{
	t_node		*head;
	t_node		*tail;
	int			size;
	t_config	*config;
}	t_stack;

void		stack_init(t_stack *stack);
t_node		*node_new(int value);
int			stack_add_back(t_stack *stack, t_node *new_node);
int			stack_load(t_stack *a, int argc, char **argv, int start);
void		stack_clear(t_stack *stack);

int			is_number(const char *s);
long		ft_atoi(const char *nptr);
int			ft_strcmp(const char *s1, const char *s2);
int			stack_repeated(t_stack *a);
float		compute_disorder(t_stack *a);
int			is_sorted(t_stack *stack);

void		push(t_stack *src, t_stack *dst);
void		push_a(t_stack *b, t_stack *a);
void		push_b(t_stack *a, t_stack *b);

void		swap(t_stack *stack);
void		swap_a(t_stack *a);
void		swap_b(t_stack *b);
void		swap_ab(t_stack *a, t_stack *b);

void		rotate(t_stack *stack);
void		rotate_a(t_stack *a);
void		rotate_b(t_stack *b);
void		rotate_ab(t_stack *a, t_stack *b);

void		reverse_rotate(t_stack *stack);
void		reverse_rotate_a(t_stack *a);
void		reverse_rotate_b(t_stack *b);
void		reverse_rotate_ab(t_stack *a, t_stack *b);

void		print_operation(char *operation, t_stack *a);

void		algo(t_stack *a, t_stack *b, t_strategy strategy);

t_node		*find_max(t_stack *stack);
int			find_position(t_stack *stack, t_node *node);
t_node		*find_min(t_stack *stack);

void		sort_two(t_stack *a);
void		sort_three(t_stack *a);
void		sort_small(t_stack *a, t_stack *b);
void		move_to_top(t_stack *stack, int position, char name);
void		simple_sort(t_stack *a, t_stack *b);
void		complex_sort(t_stack *a, t_stack *b);

void		assign_indexes(t_stack *a);
int			find_chunk_position(t_stack *a, int limit);
void		medium_sort(t_stack *a, t_stack *b);

void		adaptive_sort(t_stack *a, t_stack *b, float disorder);

int			ft_putchar(char c);
int			ft_putnbr(int n);
int			ft_putflt(double num);
int			ft_printf(const char *string, ...);

int			is_strategy_flag(char *arg);
t_strategy	parse_strategy(char *arg);

void		config_init(t_config *config);
void		bench_count(t_config *config, char *op);
int			print_total(t_config *config);
void		bench_print(t_config *config);
void		bench_print_strategy(t_config *config);

#endif
