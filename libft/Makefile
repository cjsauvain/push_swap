# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 15:21:43 by jsauvain          #+#    #+#              #
#    Updated: 2022/09/07 10:53:11 by jsauvain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_strlen.c ft_strncmp.c ft_atol.c ft_itoa.c ft_strdup.c ft_strjoin.c ft_split.c \
		ft_format.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_unsigned_putnbr.c \
		low_hexa.c put_hexa_ptr.c to_find.c up_hexa.c ft_lstnew.c ft_lstclear.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

OBJS = $(SRCS:.c=.o)

NAME = libft.a

RM = rm -f

AR = ar rcs

all: $(NAME)

clean:
		$(RM) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

fclean: clean
		$(RM) $(NAME)

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
