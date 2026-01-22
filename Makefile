NAME = rush-02
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
INC = -I includes

SRC = main.c parsing.c algo.c read_utils.c string_utils.c string_utils2.c \
      line_foos.c dict_foos.c dict_pars.c split.c string_utils3.c algo_utils.c
OBJ_DIR = objects
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

# Création du dossier objects
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)


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

