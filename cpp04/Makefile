NAME = animal

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iheaders

SRC = src = src/main.cpp \
	src/Animal.cpp \
	src/Dog.cpp \
	src/Cat.cpp

OBJ = $(SRC:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all