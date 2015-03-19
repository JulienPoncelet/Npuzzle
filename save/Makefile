# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jponcele <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/23 13:17:44 by jponcele          #+#    #+#              #
#    Updated: 2015/01/23 13:17:44 by jponcele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = npuzzle

DIRSRC = ./srcs/
DIROBJ = ./.obj/

SRC  = 	main.cpp\
		check_input.cpp\
		Npuzzle.cpp\
		Npuzzle_solver.cpp\
		Npuzzle_heuristiques.cpp\
		Npuzzle_Astar.cpp\
		Npuzzle_end.cpp\

OBJ = $(SRC:.cpp=.o)

DIROBJS = $(addprefix $(DIROBJ), $(OBJ))

HEADERS = ./headers/

CC = clang++
CFLAGS= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(DIROBJS)
	@$(CC) $(CFLAGS) -o $@ $^
	@printf 'Compiling %s : [\033[32mDONE\033[0m]\n' '$(NAME)'

$(DIROBJ)%.o: $(DIRSRC)%.cpp
	@mkdir -p $(DIROBJ)
	@$(CC) $(CFLAGS) -c $^ -I $(HEADERS) -o $@
	@printf 'Compiling %s: [\033[32mDONE\033[0m]\n' '$^'

clean:
	@rm -rf $(DIROBJ)
	@printf 'Clean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'

fclean: clean
	@rm -rf $(NAME)
	@printf 'Fclean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'

re : fclean all

test: $(NAME)
	@./$(NAME) misc/4x4.txt

.PHONY: all clean fclean re