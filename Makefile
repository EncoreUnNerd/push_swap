NAME = push_swap

LIBFT_DIR = libft
PRINTF_DIR = ft_printf

SRCS = push_swap.c
SRCS_UTILITIES = stack_utilities/advanced_stack_operations.c \
				stack_utilities/stack_initialization.c \
				stack_utilities/stack_management.c \
				stack_utilities/stack_operations_helper.c \
				stack_utilities/stack_operations.c \
				stack_utilities/stack_utilities.c \
				stack_utilities/stack_push_operations.c

OBJS = $(SRCS:.c=.o)
OBJS_UTILITIES = $(SRCS_UTILITIES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS_UTILITIES) $(OBJS) $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a
	@$(CC) $(CFLAGS) -o $@ $^
	@printf "push_swap compiled ✅\n"

$(LIBFT_DIR)/libft.a:
	@make -sC $(LIBFT_DIR)

$(PRINTF_DIR)/libftprintf.a:
	@make -sC $(PRINTF_DIR)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "."

clean:
	@make fclean -sC $(LIBFT_DIR)
	@make fclean -sC $(PRINTF_DIR)
	@rm -f $(OBJS_UTILITIES)
	@rm -f $(OBJS)
	@printf "cleaned 🧹\n"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
