# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ferde-so <ferde-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/09 16:01:54 by iscarval          #+#    #+#              #
#    Updated: 2026/07/30 04:20:44 by ferde-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -Iincludes

SRC = \
	main.c \
	core/logic.c \
	core/flag_parser.c \
	core/printer.c \
	stack/stack_creation.c \
	stack/stack_utils.c \
	operations/push.c \
	operations/swap.c \
	operations/rotate.c \
	operations/reverse_rotate.c \
	operations/operation_print.c \
	algorithms/small.c \
	algorithms/simple.c \
	algorithms/medium.c \
	algorithms/complex.c \
	configurations/config.c \
	configurations/benchmark_print.c \
	configurations/benchmark_strategy.c

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