NAME	:= push_swap

CC		:= cc

CFLAGS	:= -Wall -Wextra -Werror -Wunreachable-code -Ofast

SRCS	:= push_swap.c \
			ps_commands.c \
			ps_commands_1.c \
			ps_commands_2.c \
			choose_move.c \
			ps_tools_1.c \
			ps_tools_2.c \
			smart_rotate.c \

OBJS	:= ${SRCS:.c=.o}

LIBFT	:= libft/libft.a

all: ${NAME}

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): ${OBJS} ${LIBFT}
	$(CC) $(CFLAGS) -o $@ $^

${LIBFT}:
	@$(MAKE) -C libft/ all

clean:
	@rm -rf $(OBJS)
	@$(MAKE) -C libft/ fclean

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re