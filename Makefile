# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/01 22:23:36 by anri              #+#    #+#              #
#    Updated: 2019/10/06 05:41:51 by apavlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++

FLAGS = -Wall -Wextra -Werror

NAME = ft_retro

SRC = AEnemy.cpp AMoving.cpp AProjectile.cpp Ammo.cpp Player.cpp main.cpp

SRC_DIR = ./src/

OBJ_DIR = ./obj/

INCLUDES = -lncurses

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

all: obj_dir $(NAME)

obj_dir:
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
