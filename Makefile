#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 20:05:23 by cmiran            #+#    #+#              #
#    Updated: 2019/05/27 00:30:02 by cmiran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc -g
CFLAGS= -Wall -Wextra -Werror

LIB= libft/

INC= $(addprefix -I, .)

NAME_1= push_swap
NAME_2= checker

OBJDIR= .obj/
OBJ_1= $(addprefix $(OBJDIR), $(SRC_1:.c=.o))
OBJ_2= $(addprefix $(OBJDIR), $(SRC_2:.c=.o))

SRC_1= push_swap.c\
	parse.c\
	swap.c\
	push.c\
	rotate.c\
	quicksort.c\
	insertionsort.c\
	sequence.c\
	tools.c

SRC_2= checker.c\
	parse.c\
	swap.c\
	push.c\
	rotate.c\
	tools.c

all: lib $(NAME_1) $(NAME_2)

lib:
	@make -C ./libft

$(OBJDIR)%.o: %.c
	@mkdir -p $(OBJDIR)
	@echo "\033[0;33m      Compiling:\033[0m" $<
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC)

$(NAME_1): $(OBJ_1)
	@echo "\033[0;32m  Creating executable...\033[0m"
	@$(CC) $(CFLAGS) $^ -L $(LIB) -lft -o $@
	@ls push_swap

$(NAME_2): $(OBJ_2)
	@echo "\033[0;32m  Creating executable...\033[0m"
	@$(CC) $(CFLAGS) $^ -L $(LIB) -lft -o $@
	@ls checker

clean:
	@echo "\033[0;31mDeleting:\033[0m"	./$(OBJDIR)
	@rm -rf $(OBJDIR)

fclean: clean
	@make fclean -C ./libft
	@echo "\033[0;31mDeleting:\033[0m"	./$(NAME_1)
	@rm -f $(NAME_1)
	@echo "\033[0;31mDeleting:\033[0m"	./$(NAME_2)
	@rm -f $(NAME_2)

re: fclean all

.PHONY: all clean fclean re
