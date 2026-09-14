# VARS
NAME	= cub3d
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3
LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_FILES	= main.c	\
				parser.c

SRC_DIR = src

SRCS	= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJS_DIR	= obj

OBJS	= $(addprefix $(OBJS_DIR)/, $(SRC_FILES:.c=.o))

# RECIPES

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $@

$(OBJS_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR) all --no-print-directory


unit-tests:
	$(CC) $(CFLAGS) ./src/tests/cmocka.spec.c -lcmocka -o test-report
	./test-report

# CLEAN

clean:
	$(MAKE) -sC $(LIBFT_DIR) $@
	rm -fr $(OBJS_DIR)
	rm -rf test-report

fclean: clean
	rm -f $(NAME)
	$(MAKE) -sC $(LIBFT_DIR) $@

re: fclean all

.PHONY: all clean fclean re unit-tests
