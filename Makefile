# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romdo-na <romdo-na@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/05 10:41:02 by willpere          #+#    #+#              #
#    Updated: 2026/06/27 11:47:08 by romdo-na         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = push_swap.c push_swap_utils.c parsing/parse_arguments.c \
	push_swap_atoi.c fill_stack_a.c stack_add_last.c \
	parsing/check_duplicate.c parsing/is_valid_number.c \
	operations/push_operations.c operations/reverse_rotate_operations.c \
	operations/rotate_operations.c operations/swap_operations.c \
	disorder.c set_rank.c sort.c stack_utils.c simple_algorithm.c \
	benchmark.c my_lib/ft_putstr_fd.c
		
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re