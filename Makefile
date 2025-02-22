# Name of the executable
NAME	= philo

# Compiler and compilation flags
CC		= cc
CFLAGS 	= -Wall -Wextra -Werror

# Headers directory
INCLUDES = -I./includes

# List of source files
SRC = \
		srcs/init.c \
		srcs/main.c \
		srcs/monitor.c \
		srcs/routine.c \
		srcs/time.c \
		srcs/utils_routine.c \
		srcs/utils.c

# Convert .c files to .o files
OBJ = $(SRC:.c=.o)

# ANSI color codes (without quotes)
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
RED		= \033[1;31m
RESET	= \033[0m

# Default rule: compile the executable
all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(YELLOW)Linking objects...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@printf "$(GREEN)Compilation finished!$(RESET)\n"

# Rule to compile each .c file into a .o file
%.o: %.c
	@printf "$(BLUE)Compiling %s $(RESET)" "$<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf " [####################] 100%%\n"

# Remove object files
clean:
	@rm -f $(OBJ)
	@printf "$(RED)Object files have been removed.$(RESET)\n"

# Remove object files and the executable
fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)The executable has been removed.$(RESET)\n"

# Recompile the entire project
re: fclean all

.PHONY: all clean fclean re
