# Variables for compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Final binary
NAME = libftprintf.a

# Source objects
SRCS = ft_char_in_set.c \
ft_printf.c \
ft_putchar.c \
ft_puthex.c \
ft_putnbr.c \
ft_putptr.c \
ft_putstr.c \
ft_putunbr.c

OBJS = $(SRCS:.c=.o)

# Default target
all: $(NAME)

# Compilation
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Linking
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS) 

# Commands
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Protected words
.PHONY: all clean fclean re
