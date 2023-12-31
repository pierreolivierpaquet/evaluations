# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macote <macote@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 11:36:15 by macote            #+#    #+#              #
#    Updated: 2023/04/05 16:16:50 by macote           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	:= fdf
CFLAGS	:= -g -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBFT 	:= ./libft
LIBS 	:= $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -ldl -pthread -lm -L$(LIBMLX)/build -L/Users/$(USER)/.brew/lib -lglfw
SRCS	:= src/draw.c \
			src/fdf.c \
			src/free.c \
			src/hooks_utils.c \
			src/hooks.c \
			src/parse_map.c \
			src/points_operations.c \
			src/projections.c \
			src/set_window.c \
			src/user_interface.c \
			src/utils.c
SRCSLIB	:= $(shell find ./libft -iname "*.c")
OBJS	:= ${SRCS:.c=.o}
OBJSLIB	:= ${SRCSLIB:.c=.o}

all: libmlx lib $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

lib:
	@make -C $(LIBFT) all
	
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) $(CFLAGS)

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJSLIB)
	@# @rm -f $(LIBMLX)/build

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx