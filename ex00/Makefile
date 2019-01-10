# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achavy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/14 14:43:56 by achavy            #+#    #+#              #
#    Updated: 2018/09/16 19:55:23 by achavy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr

SRC =	main.c \
		ft_putchar.c \
		ft_strlen.c \
		ft_putnbr.c \
	   	ft_atoi.c \
		ft_itoa_eval_expr.c \
		ft_calc.c

TMP = $(SRC:.c=.o)


CC = gcc -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) -c $(SRC) -I .
	$(CC) $(TMP) -o $(NAME) -I .

clean :
	rm -f $(TMP)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
