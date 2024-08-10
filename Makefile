# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 19:21:10 by adrmarqu          #+#    #+#              #
#    Updated: 2024/03/26 13:23:14 by adrmarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECK = checker

SRC = $(wildcard src/*.c src/main/*.c)
CHECK_SRC = $(wildcard src/*.c src/bonus/*.c)

OBJ = $(SRC:.c=.o)
CHECK_OBJ = $(CHECK_SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

RM = rm -rf

all: $(NAME)

bonus: $(CHECK)

$(NAME): $(OBJ)
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $^ -o $@ -Llibft -lft

$(CHECK): $(CHECK_OBJ)
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $^ -o $@ -Llibft -lft

%.o: %.c include/push_swap.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C ./libft clean
	@$(RM) $(OBJ) $(CHECK_OBJ)
	@echo "clean of push_swap"

fclean:
	@$(MAKE) -C ./libft fclean
	@$(RM) $(OBJ) $(CHECK_OBJ)
	@$(RM) $(NAME) $(CHECK)
	@echo "fclean of push_swap"

re: fclean all

.PHONY: all clean fclean re bonus libft

