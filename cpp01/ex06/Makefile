NAME = harlFilter

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iheaders

SRC = src/main.cpp \
	src/harl.cpp

OBJ = $(SRC:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all