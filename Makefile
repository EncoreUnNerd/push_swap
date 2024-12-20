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

GREEN = \033[32m
BLUE = \033[34m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS_UTILITIES) $(OBJS) $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a
	@printf "$(BLUE)[💭] push_swap compiling$(RESET)\n"
	@$(CC) $(CFLAGS) -o $@ $^
	@printf "$(GREEN)[✅] push_swap compiled$(RESET)\n"

$(LIBFT_DIR)/libft.a:
	@printf "$(BLUE)[💭] libft compiling$(RESET)\n"
	@make -sC $(LIBFT_DIR)
	@printf "$(GREEN)[✅] libft compiled$(RESET)\n"

$(PRINTF_DIR)/libftprintf.a:
	@printf "$(BLUE)[💭] libftprintf compiling$(RESET)\n"
	@make -sC $(PRINTF_DIR)
	@printf "$(GREEN)[✅] libftprintf compiled$(RESET)\n"

clean:
	@printf "$(BLUE)[🧹] cleaning$(RESET)\n"
	@make fclean -sC $(LIBFT_DIR)
	@make fclean -sC $(PRINTF_DIR)
	@rm -f $(OBJS_UTILITIES)
	@rm -f $(OBJS)
	@printf "$(GREEN)[✨] cleaned$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(GREEN)[✨] fully cleaned$(RESET)\n"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

.PHONY: all clean fclean re
