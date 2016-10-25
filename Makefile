# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/02 01:49:59 by vthomas           #+#    #+#              #
#    Updated: 2016/10/25 01:39:00 by vthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell

SRC_NAME = main.c\
		   get_next_line.c\
		   prompt.c\
		   env.c\
		   event.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH = ./src/
OBJ_PATH = ./obj/

SRC=$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ=$(addprefix $(OBJ_PATH),$(OBJ_NAME))

LIB = -L ./libft -L ./DebugLib -lft -ldbg
INC = -I ./include -I ./libft -I ./DebugLib/include
FMW =

CFLAGS = -Wall -Wextra -Weverything -Wno-missing-noreturn -g -Wno-padded

all: $(NAME)

$(NAME): lib $(OBJ)
	@printf "\033[34;1m\n▶    \033[0;32;1m✔ \033[0;34;1mSources\033[0;32;1m ✔\033[0;34;1m    ◀\033[0m\n"
	@printf "\033[90m--------------------------------------------------------------------------------\033[0m\n"
		@printf "\033[34m▶    \033[4mLINK\033[0;34m    ◀\033[0m\n"
	@gcc $(CFLAGS) $(LIB) $(INC) $(FMW) $(OBJ) -o $@
	@chmod +x $(NAME)
	@printf "\033[34;1m\n▶    \033[0;32;1m✔ \033[0;34;1mLink\033[0;32;1m ✔\033[0;34;1m    ◀\033[0m\n"
	@printf "\033[90m--------------------------------------------------------------------------------\033[0m\n"

lib:
	@printf "\033[34m▶    \033[4mLIBRAIRIES\033[0;34m    ◀\033[0m\n"
	@printf "\033[32;4m▶\tLIBFT\033[0m\n"
	@make -C ./libft
	@printf "\033[32;4m▶\tLIBDBG\033[0m\n"
	@make -C ./DebugLib
	@printf "\033[34;1m\n▶    \033[0;32;1m✔ \033[0;34;1mLibrairies\033[0;32;1m ✔\033[0;34;1m    ◀\033[0m\n"
	@printf "\033[90m--------------------------------------------------------------------------------\033[0m\n"
	@printf "\033[34m▶    \033[4mSOURCES\033[0;34m    ◀\033[0m\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	gcc $(CFLAGS) $(INC) -c -o $@ $<

clean:
	-@rm -rf $(OBJ_PATH)
	@make -C ./libft $@
	@make -C ./DebugLib $@

fclean: clean
	-@rm $(NAME)
	@make -C ./libft $@
	@make -C ./DebugLib $@
	@printf "🦄  There is no more unicorn poop 🦄\n"

re: fclean all

test: re
	@clear
	./$(NAME) | cat -e
.PHONY: fclean clean
