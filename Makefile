# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 20:05:23 by cmiran            #+#    #+#              #
#    Updated: 2019/04/27 19:14:06 by cmiran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

CC= gcc
CFLAGS= -Wall -Wextra -Werror

SRC_NAME= main.c
SRC= $(addprefix ./,$(SRC_NAME))

LIB= ./libft/

OBJ= $(addprefix obj/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): lib obj
	$(CC) $(CFLAGS) $(OBJ) -L $(LIB) -lft -o $@

lib:
	make -C ./libft

obj:
	mkdir -p obj
	$(CC) $(CFLAGS) -o $(OBJ) -c $(SRC) -I ./ -I ./libft

clean:
	make clean -C ./libft
	rm -rf $(OBJ) obj/

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
