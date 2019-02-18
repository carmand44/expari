# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carmand <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 21:43:02 by carmand           #+#    #+#              #
#    Updated: 2019/02/18 23:22:24 by achavy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = expari

SRC =	main.c \
		ft_erase_space.c \
		ft_math_op.c \
		ft_true_op.c \
		ft_logic_op.c \
		ft_itoa_exp_ari.c \
		ft_exp_ari_error.c

TMP = $(SRC:.c=.o)

LIB = libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all : $(NAME)

$(NAME): $(LIB) $(SRC)
	$(CC) $(FLAGS) -c $(SRC) -I . -I ./libft
	$(CC) $(FLAGS) $(TMP) -o $(NAME)  -L ./libft -lft -I . -I ./libft/

$(LIB):
	make -C libft

clean:
	rm -f $(TMP)
	make -C libft clean

noflags: $(LIB) $(SRC)
	$(CC) -c $(SRC) -I . -I ./libft
	$(CC) $(TMP) -o $(NAME)  -L ./libft -lft -I . -I ./libft/


fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re : fclean all
