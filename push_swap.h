/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iscarval <iscarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 14:27:15 by iscarval          #+#    #+#             */
/*   Updated: 2026/07/16 20:50:58 by iscarval         ###   ########.fr       */
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

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

void	stack_init(t_stack *stack);
t_node	*node_new(int value);
int		stack_add_back(t_stack *stack, t_node *new_node);
int		stack_load(t_stack *a, int argc, char **argv);
void	stack_clear(t_stack *stack);

int		is_number(const char *s);
int		ft_atoi(const char *nptr);
int		stack_repeated(t_stack *a);
float	compute_disorder(t_stack *a);

int		stack_operations_test(t_stack *a, t_stack *b);
int		stack_valid(t_stack *stack);
void	stack_print(t_stack *stack, char name, int flag);

void	push(t_stack *src, t_stack *dst);
void	push_a(t_stack *b, t_stack *a);
void	push_b(t_stack *a, t_stack *b);

void	swap(t_stack *stack);
void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swap_ab(t_stack *a, t_stack *b);

void	rotate(t_stack *stack);
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_ab(t_stack *a, t_stack *b);

void	reverse_rotate(t_stack *stack);
void	reverse_rotate_a(t_stack *a);
void	reverse_rotate_b(t_stack *b);
void	reverse_rotate_ab(t_stack *a, t_stack *b);

void	algo(t_stack *a, t_stack *b);

t_node	*find_max(t_stack *stack);
int		find_position(t_stack *stack, t_node *node);
t_node	*find_min(t_stack *stack);

void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
void	move_to_top(t_stack *a, int position);

int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putflt(double num);
int		ft_printf(const char *string, ...);

#endif
