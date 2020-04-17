# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 14:25:24 by jsalmi            #+#    #+#              #
#    Updated: 2020/03/05 15:45:07 by nneronin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
SRCS = ./checker.c\
	   ./read_input.c\
	   ./call_func.c\
	   ./moves/s_moves.c\
	   ./moves/p_moves.c\
	   ./moves/r_moves.c\
	   ./moves/rr_moves.c
OBJS = $(SRCS:.c=.o)
INCLUDES = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(FLAGS) $(SRCS) $(INCLUDES)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean, all, re, fclean
