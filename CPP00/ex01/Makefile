# Name of the program
NAME = phonebook

# Compiler
CC = c++

# Compiler flags
CFLAGS := -Wall -Wextra -Werror -std=c++98 -Iheaders/

# Source files
SRC = src/phonebook.cpp \
	src/main.cpp \
	src/contact.cpp
	  
# Object files
OBJ = $(SRC:.cpp=.o)

# Phony targets for make commands
.PHONY: all clean fclean re

# Default target
all: $(NAME)

# Rule to link the program
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) 

# Rule to compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(NAME)

# Rule to fully clean the project, including the executable
fclean: clean
	rm -f $(NAME)

# Rule to re-make the project
re: fclean all
