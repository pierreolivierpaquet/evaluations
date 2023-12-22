# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 17:44:44 by brheaume          #+#    #+#              #
#    Updated: 2023/08/02 10:55:50 by ppaquet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = time.c \
	  utils.c \
	  main.c \
	  angel.c \
	  alive.c \
	  verify.c \
	  seeker.c \
	  annihilation.c \
	  initialization.c \

OBJ = ${SRC:.c=.o}

CC = gcc -g
CFLAGS = -Wextra -Wall -Werror -pthread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

sani: CFLAGS += -fsanitize=thread
sani: clean all

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
