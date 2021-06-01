# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/31 10:38:28 by nneronin          #+#    #+#              #
#    Updated: 2021/06/01 17:00:00 by nneronin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED				:= "\e[0;31m"
GREEN			:= "\e[0;32m"
YELLOW			:= "\e[0;33m"
BLUE			:= "\e[0;34m"
MAGENTA			:= "\e[0;35m"
CYAN			:= "\e[0;36m"
RESET			:= "\e[0m"

NAME = push_swap
SRCS = ./push_swap.c\
	   ./read_input.c\
	   ./sort_algo.c\
	   ./moves/s_moves.c\
	   ./moves/p_moves.c\
	   ./moves/r_moves.c\
	   ./moves/rr_moves.c\
	   ./help_func.c\
	   ./find_and_move.c\
	   ./short_algo.c

OBJS			= $(SRCS:.c=.o)
LIB_DIR			:= ../lib
LIBFT			:= -I $(LIB_DIR)/libft $(LIB_DIR)/libft/libft.a
LIBPF			:= -I $(LIB_DIR)/libpf $(LIB_DIR)/libpf/libpf.a
LIBS			= $(LIBFT) $(LIBPF)
CFLAGS			= -Wall -Wextra -Werror

all: $(NAME)
	@printf $(GREEN)"$(NAME) ready!\n"$(RESET)

$(NAME):
	@printf $(CYAN)"[INFO]	Compiling $(NAME)\n"$(RESET)
	@gcc -o $(NAME) $(SRCS) $(LIBS) #$(CFLAGS)

clean:
	@/bin/rm -f $(OBJS)
	@printf $(CYAN)"[INFO]	$(NAME) cleaned\n"$(RESET)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean, all, re, fclean
