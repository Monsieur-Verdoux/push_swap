NAME	:= push_swap

CC		:= cc

CFLAGS	:= -Wunreachable-code -Ofast

SRCS	:= push_swap.c \
			ps_commands.c \

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