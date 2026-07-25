# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iscarval <iscarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/09 16:01:54 by iscarval          #+#    #+#              #
#    Updated: 2026/07/23 18:57:09 by iscarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -Iincludes

SRC = \
	main.c \
	logic.c \
	flag_parser.c \
	stack_creation.c \
	stack_utils.c \
	stack_debug.c \
	operation_push.c \
	operation_swap.c \
	operation_rotate.c \
	operation_reverse_rotate.c \
	algorithm_small.c \
	algorithm_simple.c \
	algorithm_medium.c \
	algorithm_complex.c \
	algorithm_complex_utils.c \
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