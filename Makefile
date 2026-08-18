# VARS
NAME	= cub3d
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3

SRC_DIR = src

SRC_FILES	= main.c

SRCS	= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJS_DIR	= obj

OBJS	= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

# RECIPES

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS_DIR)/%.o : %.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

unit-test:
	cc -Wall -Wextra -Werror ./src/test/cmocka.spec.c -lcmocka -o test-report
	./test-report

# CLEAN

clean:
	rm -fr $(OBJS_DIR)
	rm -rf test-report

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re unit-test
