NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_putnbr_base.c ft_put.c ft_printf.c
OBJS = $(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@printf "libftprintf compiled ✅\n"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "."

clean:
	@rm -f $(OBJS)
	@printf "."

fclean: clean
	@rm -f $(NAME)
	@printf "."

re: fclean all

.PHONY: all clean re fclean