# --------------- VARS ----------------
NAME	= cub3d

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3
LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_FILES	=	main.c	\
				parser.c

SRC_DIR = src
SRCS	= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJS_DIR	= obj
OBJS	= $(addprefix $(OBJS_DIR)/, $(SRC_FILES:.c=.o))


# ------------ RECIPES ---------------

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $@

$(OBJS_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
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

# -------------- CLEAN ----------------

clean:
	$(MAKE) -sC $(LIBFT_DIR) $@
	rm -fr $(OBJS_DIR)
	rm -fr $(TEST_OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -fr $(TEST_OBJ_DIR)
	$(MAKE) -sC $(LIBFT_DIR) $@

re: fclean all

.PHONY: all clean fclean re unit-tests
