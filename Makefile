# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 14:33:12 by jsauvain          #+#    #+#              #
#    Updated: 2022/09/07 10:53:44 by jsauvain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_pushswap.c swap_functions.c ft_utils.c ft_sort.c check_args.c print_operations.c \
		ft_free.c small_digits.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

CLR = clear

all: $(NAME)

clean:
		make clean -sC libft
		$(RM) $(OBJS) $(CLR)

fclean: clean
		make fclean -sC libft
		$(RM) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		$(CLR)
		make -sC libft
		$(CC) $(CFLAGS) -o $(NAME) -L. $(OBJS) -L./libft -lft

re: fclean all

.PHONY: all clean fclean re
