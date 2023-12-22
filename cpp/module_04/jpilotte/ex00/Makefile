CC=g++
CFLAGS=-Wall -Wextra -Werror -std=c++98
SRC=./main.cpp ./Animal.cpp ./Dog.cpp ./Cat.cpp ./WrongAnimal.cpp ./WrongCat.cpp
OBJ=$(SRC:.cpp=.o)
NAME=exec
PDF=https://cdn.intra.42.fr/pdf/pdf/93103/en.subject.pdf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

pdf:
	$(shell open $(PDF))

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all