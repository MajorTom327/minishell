# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/02 01:49:59 by vthomas           #+#    #+#              #
#    Updated: 2016/12/11 03:19:54 by vthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell

SRC_NAME = main.c\
		   builtin/b_echo.c\
		   builtin/b_env.c\
		   builtin/b_pwd.c\
		   init/cmd.c\
		   init/env.c\
		   init/env_imp.c\
		   init/prompt.c\
		   input/get_next_line.c\
		   input/parse/clean.c\
		   other/cmd_search.c\
		   other/env_search.c\
		   other/execute.c\
		   other/exit.c\
		   other/hash.c\
		   other/loop.c

OBJ_NAME = $(SRC_NAME:.c=.o)

DBG_OUTPUT = /dev/ttys001
SRC_PATH = ./src/
OBJ_PATH = ./obj/
OBJ_SUB = builtin init input input/parse other

SRC=$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ=$(addprefix $(OBJ_PATH),$(OBJ_NAME))

LIB = -L libft -L DebugLib -lft -ldbg
INC = -I include -I libft -I DebugLib/include
FMW =

CC = clang

#CFLAGS = -Wall -Wextra -Weverything -Wno-missing-noreturn -g -Wno-padded
CFLAGS = -Wall -Wextra -g -Wno-unused-parameter -Ofast -Os

all: $(NAME)

$(NAME): lib $(OBJ)
	@printf "\033[34;1m\n▶    \033[0;32;1m✔ \033[0;34;1mSources\033[0;32;1m ✔\033[0;34;1m    ◀\033[0m\n"
	@printf "\033[90m--------------------------------------------------------------------------------\033[0m\n"
	@printf "\033[34m▶    \033[4mLINK\033[0;34m    ◀\033[0m\n"
	$(CC) $(CFLAGS) $(OBJ) $(INC) $(LIB) $(FMW) -o $@
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
	@mkdir -p $(addprefix $(OBJ_PATH),$(OBJ_SUB))
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

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

test: all
	@clear
	@clear > $(DBG_OUTPUT)
	@$(CC) $(CFLAGS) ./printenv.c -o printenv
	@echo "\033[32;4m`date`\033[0m\n" >> $(DBG_OUTPUT)
	./$(NAME) 2>> $(DBG_OUTPUT)
#	env -i ./$(NAME) 2>> $(DBG_OUTPUT)

.PHONY: fclean clean
