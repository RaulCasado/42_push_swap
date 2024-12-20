NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra -no-pie -g

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
INCLUDES = -I$(LIBFT_DIR) -I$(PRINTF_DIR)

SRC_DIR = src

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/push.c $(SRC_DIR)/reverse.c $(SRC_DIR)/swaps.c \
    $(SRC_DIR)/memory_utils.c $(SRC_DIR)/parse_utils.c $(SRC_DIR)/stack_utils.c $(SRC_DIR)/validation_utils.c \
    $(SRC_DIR)/struct_utils.c $(SRC_DIR)/order.c $(SRC_DIR)/rotate.c $(SRC_DIR)/order_utils.c \
	$(SRC_DIR)/main_utils.c $(SRC_DIR)/indexing.c $(SRC_DIR)/lis_utils.c $(SRC_DIR)/lis_mark.c \
	$(SRC_DIR)/insert_from_b.c $(SRC_DIR)/cost_and_insert.c $(SRC_DIR)/rotations.c

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

norm:
	norminette $(SRCS) $(SRC_DIR)/push_swap.h $(PRINTF_DIR)/*.c $(PRINTF_DIR)/*.h

.PHONY: all clean fclean re norm
