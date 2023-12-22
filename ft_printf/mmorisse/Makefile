
NAME = libftprintf.a

SRC = ft_printf.c

OBJS := $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I.

CC = gcc

ARNAME = ar -rcs

#LIB = ranlib


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: libs $(NAME)


${NAME}: $(OBJS)
	cp libft/libft.a $(NAME)
	$(ARNAME) $(NAME) $(OBJS)
#$(LIB) $(NAME)
	
libs:
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY:	all clean fclean re
