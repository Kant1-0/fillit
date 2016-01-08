# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 11:53:00 by qfremeau          #+#    #+#              #
#    Updated: 2016/01/08 13:04:12 by qfremeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATHLIBFT = ../libft/
PATHLIBLIST = ../lib-list/

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
	cd $(PATHLIBFT) && \
		make
	cp -f $(PATHLIBFT)libft.a lib/
	cp -f $(PATHLIBFT)libft.h lib/
	cd $(PATHLIBLIST) && \
		make
	cp -f $(PATHLIBLIST)list.a lib/
	cp -f $(PATHLIBLIST)list.h lib/

relibs:
	cd $(PATHLIBFT) && \
		make re
	cp -f $(PATHLIBFT)libft.a lib/
	cp -f $(PATHLIBFT)libft.h lib/
	cd $(PATHLIBLIST) && \
		make re
	cp -f $(PATHLIBLIST)list.a lib/
	cp -f $(PATHLIBLIST)list.h lib/

cleanlibs:
	cd $(PATHLIBFT) && \
		make fclean
	cd $(PATHLIBLIST) && \
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