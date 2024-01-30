# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 13:46:43 by akovalev          #+#    #+#              #
#    Updated: 2024/01/30 13:48:14 by akovalev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap

CC		:= cc

CFLAGS	:= -Wall -Wextra -Werror

SRCS	:= push_swap.c \
			ps_commands.c \
			ps_commands_1.c \
			ps_commands_2.c \
			choose_move.c \
			ps_tools_1.c \
			ps_tools_2.c \
			smart_rotate.c \
			main.c

BONUS_SRCS := checker_bonus.c \
				push_swap.c \
				ps_commands.c \
				ps_commands_1.c \
				ps_commands_2.c \
				choose_move.c \
				ps_tools_1.c \
				ps_tools_2.c \
				smart_rotate.c

OBJS	:= ${SRCS:.c=.o}

BONUS_OBJS := ${BONUS_SRCS:.c=.o} Libft/libft.a 

LIBFT	:= Libft/libft.a

all: ${NAME}

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): ${OBJS} ${LIBFT}
	@$(CC) $(CFLAGS) -o $@ $^

${LIBFT}:
	@$(MAKE) -C libft/ all

bonus: checker

checker: $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o checker

clean:
	@rm -rf $(OBJS) checker_bonus.o
	@$(MAKE) -C libft/ fclean

fclean: clean
	@rm -rf $(NAME) checker

re: clean all

.PHONY: all, clean, fclean, re, bonus