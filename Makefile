# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 11:53:00 by qfremeau          #+#    #+#              #
#    Updated: 2016/01/07 11:08:55 by qfremeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c read_file.c creat_list.c check_buf.c sav_bloc.c
LIB = lib/libft.a lib/list.a
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all:
	clang $(FLAGS) -c $(SRC)
	clang -o $(NAME) $(FLAGS) $(OBJ) $(LIB)

$(NAME): all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

libs:
	cd ../lib-list && \
		make
	cp -f ../lib-list/list.a lib/
	cp -f ../lib-list/list.h lib/
	cd ../libft && \
		make
	cp -f ../libft/libft.a lib/
	cp -f ../libft/libft.h lib/

relibs:
	cd ../lib-list && \
		make re
	cp -f ../lib-list/list.a lib/
	cp -f ../lib-list/list.h lib/
	cd ../libft && \
		make re
	cp -f ../libft/libft.a lib/
	cp -f ../libft/libft.h lib/

cleanlibs:
	cd ../lib-list && \
		make fclean
	cd ../libft && \
		make fclean
	rm -f lib/list.a lib/list.h lib/libft.a lib/libft.a

retetris:
	cd generator/ && \
		make re

validtetris:
	cd generator/ && \
		./tetri-gen -v -f 6
	cp -f generator/sample.fillit ./
	cat -e sample.fillit

invalidtetris:
	cd generator/ && \
		./tetri-gen -i -f 6
	cp -f generator/sample.fillit ./
	cat -e sample.fillit