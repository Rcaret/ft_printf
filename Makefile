# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: litoulza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/21 14:57:04 by litoulza          #+#    #+#              #
#    Updated: 2017/12/21 18:26:11 by litoulza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
CC = gcc
SRC_PRINTF = src_printf/
NAME_SRC = check_conversion.o conversion_1.o conversion_2.o \
			conversion_in_char.o fct_aux.o fct_aux2.o flag1.o flag2.o ft_atoi.o \
			ft_itoa.o ft_itoa1.o ft_itoa2.o ft_printf.o ft_strcat.o ft_strchr.o \
			ft_strcpy.o ft_strdup.o ft_strjoin.o ft_strlen.o ft_strncmp.o \
			itoa_alloc.o unicode.o
SRC = $(patsubst %.o,$(SRC_PRINTF)%.o,$(NAME_SRC))

all: $(NAME)

e: all
	gcc main.c libftprintf.a
	./a.out

ee: all
	gcc main.c libftprintf.a
	./a.out | cat -e

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(SRC)
	ar rc $(NAME) $(SRC)
	ranlib $(NAME)

clean:
	/bin/rm -f $(SRC)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
