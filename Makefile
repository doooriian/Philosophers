# Nom de l'exécutable
NAME    = philo

# Compilateur et flags de compilation
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

# Répertoire des headers
INCLUDES = -I./includes

# Liste des sources
SRC = \
		srcs/init.c \
        srcs/main.c \
        srcs/monitor.c \
        srcs/routine.c \
        srcs/time.c \
        srcs/utils_routine.c \
        srcs/utils.c

# Conversion des .c en .o
OBJ = $(SRC:.c=.o)

# Codes couleurs ANSI (sans guillemets)
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
RED		= \033[1;31m
RESET	= \033[0m

# Règle par défaut : compilation de l'exécutable
all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(YELLOW)Linking objects...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@printf "$(GREEN)Compilation terminée !$(RESET)\n"

# Règle pour compiler chaque .c en .o
%.o: %.c
	@printf "$(BLUE)Compiling %s $(RESET)" "$<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf " [####################] 100%%\n"

# Supprime les fichiers objets
clean:
	@rm -f $(OBJ)
	@printf "$(RED)Les fichiers objets ont été supprimés.$(RESET)\n"

# Supprime les fichiers objets et l'exécutable
fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)L'exécutable a été supprimé.$(RESET)\n"

# Recompile entièrement le projet
re: fclean all

.PHONY: all clean fclean re
