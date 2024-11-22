NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)

SRC_DIR = src

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/push.c $(SRC_DIR)/reverse.c $(SRC_DIR)/swaps.c \
	$(SRC_DIR)/memory_utils.c $(SRC_DIR)/parse_utils.c $(SRC_DIR)/stack_utils.c $(SRC_DIR)/validation_utils.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
