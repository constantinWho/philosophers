# Name of the output executable
PHILO = philo

# Source files directory
SRC_DIR = src

# Header files directory
INC_DIR = inc

# Object files directory
OBJ_DIR = obj

# Source files

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)

# Rule to build the executable
$(PHILO): $(OBJ)
	$(CC) $(CFLAGS) -o $(PHILO) $(OBJ)

# Rule to compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build everything
all: $(PHILO)

# Rule to clean object files
clean:
	rm -f $(OBJ)

# Rule to clean object files and the executable
fclean: clean
	rm -f $(PHILO) && rmdir $(OBJ_DIR)

# Rule to clean and rebuild
re: fclean all

.PHONY: all clean fclean re


