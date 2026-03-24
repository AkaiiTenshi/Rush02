NAME = rush-02
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
INC = -I includes

SRC = srcs/main.c srcs/parsing.c srcs/algo_lookup.c srcs/algo_group.c \
	  srcs/algo_count.c srcs/algo_split.c srcs/algo_words.c \
	  srcs/algo_words_utils.c srcs/algo_zero.c srcs/algo_zero_helpers.c \
	  srcs/read_utils.c \
	  srcs/string_core.c srcs/string_alloc.c srcs/string_helpers.c \
	  srcs/line_foos.c srcs/dict_foos.c srcs/dict_pars.c srcs/split.c \
	  srcs/split_copy.c
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
