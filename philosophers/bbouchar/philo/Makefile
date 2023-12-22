# Make file By Bruno-Pierre Bouchard for 42 Philosophers
# Creation date : 09/06/2023

# Use make to build

NAME = philo

SRC = 	src/main.c		\
		src/util.c		\
		src/philo.c		\
		src/check_input.c \
		src/monitoring.c		\

CC = gcc
CFLAGS = -pthread -g -Wall -Wextra -Werror #-fsanitize=thread
INCLUDES = -I includes
$(NAME): $(SRC)
	${CC} -o ${NAME} ${SRC} ${CFLAGS} ${INCLUDES}

all: $(NAME)

clean:
	rm -f *.o
fclean: clean
	rm -f philo
re: fclean all

