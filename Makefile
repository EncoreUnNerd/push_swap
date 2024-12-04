NAME = push_swap
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
SRCS = push_swap.c swap_utils.c swap_utils2.c swap_utils3.c swap_utils4.c utils.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a
	$(CC) $(CFLAGS) -o $@ $^ 

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

$(PRINTF_DIR)/libftprintf.a:
	make -C $(PRINTF_DIR)

clean:
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
