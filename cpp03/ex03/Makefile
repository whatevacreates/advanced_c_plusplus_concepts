NAME = diamond

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iheaders

SRC = src/main.cpp \
	src/FragTrap.cpp \
	src/ClapTrap.cpp \
	src/ScavTrap.cpp \
	src/DiamondTrap.cpp

OBJ = $(SRC:.cpp=.o)

# Colors
PINK = \033[3;35m
PASTEL_GREEN = \033[38;5;120m
GREEN = \033[0;32m
RESET = \033[0m

# Messages
LAUNCH_MSG = "To Launch the program type: ./$(shell echo $(NAME) | tr 'A-Z' 'a-z')"
SUCCESS_MSG = "★ The executable $(NAME) was successfully compiled ★\n"
INFO_MSG = "Available commands:\n- all: Build the program\n- clean: Remove object files\n- fclean: Remove object files and executable\n- re: Clean and recompile everything"

.PHONY: all clean fclean re

all: $(NAME)
	@printf "$(PASTEL_GREEN)★ The executable diamond was successfully compiled ★\n\n$(RESET)"
	@printf "$(PINK)To Launch the program type: ./diamond$(RESET)\n\n"
	@printf "$(PASTEL_GREEN)Available commands:\n- all: Build the program\n- clean: Remove object files\n- fclean: Remove object files and executable\n- re: Clean and recompile everything$(RESET)\n\n"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) > /dev/null 2>&1

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null 2>&1

clean:
	@rm -f $(OBJ)
	@printf "$(GREEN)Object files cleaned.$(RESET)\n\n"

fclean: clean
	@rm -f $(NAME) 
	@printf "$(GREEN)Executable $(NAME) cleaned.$(RESET)\n\n"

re: fclean all
