# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusong <yusong@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 15:33:20 by yusong            #+#    #+#              #
#    Updated: 2017/11/17 13:39:35 by yusong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re
NAME = fillit
NOC=\033[36m
OKC=\033[36m
WAC=\033[36m
CC = gcc
CC_FLAGS = -Wall -Werror -Wextra
OBJ_PATH = ./obj/
LFT_PATH = ./libft/
SRC = $(SRC_NAME)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = fillit.h
SRC_NAME = main.c       map.c       read.c
all: $(NAME)
$(OBJ_PATH)%.o: %.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CC_FLAGS) -o $@ -c $<
	@echo -n .
$(NAME): $(OBJ)
	make -C $(LFT_PATH)
	$(CC) -o $(NAME) $(OBJ) -L $(LFT_PATH) -lft
	@echo "$(OKC)FILLIT:\t\tFillit ready$(NOC)"
clean:
	make -C $(LFT_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "$(WAC)FILLIT:\t\tRemoving OBJ path: ./obj/$(NOC)"
fclean: clean
	make -C $(LFT_PATH) fclean
	@rm -f $(NAME)
	@echo "$(WAC)FILLIT:\t\tRemoving fillit executable$(NOC)"
re: fclean all
