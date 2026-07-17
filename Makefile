# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/09 16:01:54 by iscarval          #+#    #+#              #
#    Updated: 2026/07/16 19:27:46 by ferde-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -Iincludes

SRC = \
	main.c \
	logic.c \
	stack.c \
	stack_utils.c \
	stack_debug.c \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	small_sort.c \
	algorithm_simple.c \
	printer.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re