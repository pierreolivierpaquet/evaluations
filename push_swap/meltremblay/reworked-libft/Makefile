# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 13:41:29 by meltremb          #+#    #+#              #
#    Updated: 2023/03/29 11:03:46 by meltremb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

SRCS = ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_str_isdigit.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_lstnew.c \
	   ft_lstadd_front.c \
	   ft_lstsize.c \
	   ft_lstlast.c \
	   ft_lstadd_back.c \
	   ft_lstdelone.c \
	   ft_lstclear.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_printf.c \
	   print_chars.c \
	   print_numbers.c \
	   printf_utils.c \
	   get_next_line_bonus.c \
	   get_next_line_utils_bonus.c \
	   ft_exit.c \
	   ft_free_array.c \

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
AR = ar rc
RM = rm -f
OBJS = $(SRCS:.c=.o)

$(NAME):
		-@ $(CC) $(CFLAGS) $(HIDE)$(SRCS)
		-@ $(AR) $(NAME) $(HIDE)$(OBJS)

all: $(NAME)

clean:
		-@ $(RM) $(OBJS)

fclean: clean
		-@ $(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus