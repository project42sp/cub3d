# --------------- VARS ----------------
NAME	= cub3d

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3 -std=c99
LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_FILES	=	main.c	\
				parser.c	\
				parser_utils.c	\
				parser_invalid_name.c	\
				parser_map_size_check.c		\
				input_module/key_handler.c	\
				input_module/key_register.c \
				input_module/key_action.c		\
				game_module/exit_game.c			\
				graphic_module/graphic_config.c \
				graphic_module/render_map.c

SRC_DIR = src
SRCS	= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJS_DIR	= obj
OBJS	= $(addprefix $(OBJS_DIR)/, $(SRC_FILES:.c=.o))

MLX_DIR = minilibx
MLX = $(MLX_DIR)/libmlx.a

# ------------ RECIPES ---------------

all : $(MLX) $(NAME)

$(MLX):
	@make -C minilibx

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $@ -Lminilibx -lmlx -lXext -lX11 -lm -lz

$(OBJS_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


# -------------- LIBFT ----------------

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR) all --no-print-directory

# -------------- TESTS ----------------
# ---- Variables -----
CFLAGS_TEST	= $(CFLAGS) -MMD -MP -Iincludes -Iincludes/libft/includes

# Library for tests
TEST_OBJ_DIR	= build
LIB_OBJS	= $(filter-out obj/main.o, $(OBJS))
LIBCORE		= $(TEST_OBJ_DIR)/libcore.a

# Tests files
TEST_SRCS	= $(wildcard src/tests/*.c)
TEST_BINS	= $(TEST_SRCS:src/tests/%.c=build/%)
TEST_LIBS	= -lcmocka


# ----- Recipes ------
$(LIBCORE): $(LIB_OBJS)
	@mkdir -p $(TEST_OBJ_DIR)
	ar rcs $@ $^

$(TEST_BINS): build/%: src/tests/%.c $(LIBCORE) $(LIBFT)
	@mkdir -p $(TEST_OBJ_DIR)
	$(CC) $(CFLAGS_TEST) $< $(LIBCORE) $(LIBFT) $(LDFLAGS) $(TEST_LIBS) $(LDLIBS) -o $@

unit-tests: $(TEST_BINS)
	@echo $(TEST_BINS)
	@test -n "$(TEST_BINS)" || { echo "no tests found"; exit 1; }
	@fail=0;	\
	for t in $(TEST_BINS); do	\
		echo "== $$t";			\
		./$$t || fail=1;		\
	done;						\
	exit $$fail

normi:
	@norminette $$(find . -name "*.[ch]" | grep -v tests | grep -v minilibx)

# -------------- CLEAN ----------------

clean:
	$(MAKE) -sC $(LIBFT_DIR) $@
	rm -fr $(OBJS_DIR)
	rm -fr $(TEST_OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -sC $(LIBFT_DIR) $@

val:
	@valgrind \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--track-fds=yes \
		--suppressions=mlx.supp \
		./$(NAME) maps/map.valid_with_space.cub

re: fclean all

.PHONY: all clean fclean re unit-tests
