#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

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

void stack_init(t_stack *stack); 
t_node *node_new(int value); 
void stack_add_back(t_stack *stack, t_node *new_node);
void ft_lstclear(t_node **lst, void (*del)(int)); 
int ft_atoi(const char *nptr); 
int isnumber(const char *s); 
int	ft_isdigit(int c);
int	ft_atoi(const char *nptr);
int logic(int argc, char **argv);
void print_test(t_stack *stack);

#endif
