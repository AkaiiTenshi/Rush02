NAME = rush-02
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
INC = -I includes

SRC = srcs/main.c srcs/parsing.c srcs/algo.c srcs/read_utils.c \
	  srcs/string_utils.c srcs/string_utils2.c srcs/line_foos.c \
	  srcs/dict_foos.c srcs/dict_pars.c srcs/split.c \
	  srcs/string_utils3.c srcs/algo_utils.c
OBJ_DIR = objects
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

# Création du dossier objects
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/srcs


# Compilation des .o dans objects/
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@


$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	$(CC) $(OBJS) -o $(NAME)


clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

