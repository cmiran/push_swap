#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 20:05:23 by cmiran            #+#    #+#              #
#    Updated: 2019/05/09 02:08:44 by cmiran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

CC= gcc
CFLAGS= -Wall -Wextra -Werror

SRC= main.c

LIB= libft/

INC= $(addprefix -I, .)

OBJDIR= .obj/
OBJ= $(addprefix $(OBJDIR), $(SRC:.c=.o))


all: lib $(NAME)

lib:
	@make -C ./libft

$(NAME): $(OBJ)
	@echo "\033[0;32m  Creating executable...\033[0m"
	@$(CC) $(CFLAGS) $^ -L $(LIB) -lft -o $@
	@ls push_swap

$(OBJDIR)%.o: %.c
	@mkdir -p $(OBJDIR)
	@echo "\033[0;33m      Compiling:\033[0m" $<
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC)

clean:
	@echo "\033[0;31m  Deleting:\033[0m" ./$(OBJDIR)
	@rm -rf $(OBJ) $(OBJDIR)

fclean: clean
	@make fclean -C ./libft
	@echo "\033[0;31mDeleting:\033[0m" ./$(NAME)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
