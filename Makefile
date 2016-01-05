# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 11:53:00 by qfremeau          #+#    #+#              #
#    Updated: 2016/01/05 18:40:10 by qfremeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c reading.c listing.c
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

retetri:
	cd generator/ && \
		make re

tetrivalid:
	cd generator/ && \
		./tetri-gen -v -f 6
	cp -f generator/sample.fillit ./
	cat -e sample.fillit

tetrifalse:
	cd generator/ && \
		./tetri-gen -i -f 6
	cp -f generator/sample.fillit ./
	cat -e sample.fillit