# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 17:00:31 by adrmarqu          #+#    #+#              #
#    Updated: 2024/03/26 13:23:45 by adrmarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR = ar rcs
RM = rm -f
CC = gcc
CCFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC =  $(wildcard ft_printf/*.c libft/*.c)
OBJ = $(SRC:.c=.o)

INCLUDE = ft_printf/ft_printf.h libft/libft.h

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

%.o: %.c $(INCLUDE) Makefile
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJ)
	@echo "clean of libft"

fclean:
	@$(RM) $(OBJ)
	@$(RM) $(NAME)
	@echo "fclean of libft"

re: fclean all

.PHONY : all clean fclean re
