# Name of the executable
NAME = megaphone

# Compiler
CC = g++

CFLAGS := -Wall -Wextra -Werror -std=c++98

# Source files
SRC = megaphone.cpp
	  
# Object files
OBJ = $(SRC:.cpp=.o)

# Phony targets for make commands
.PHONY: all clean fclean re

# Default target
all: $(NAME)

# Rule to link the program
$(NAME): $(OBJ) 
	$(CC) $(OBJ) -o $(NAME) 
#$(LDFLAGS)
# Rule to compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean object files and other temporary files
clean:
	rm -f $(OBJ) $(NAME)

# Rule to fully clean the project, including the executable
fclean: clean
	rm -f $(NAME)

# Rule to re-make the project
re: fclean all