# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 14:25:24 by jsalmi            #+#    #+#              #
#    Updated: 2020/03/05 17:59:23 by nneronin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visualizer
SRCS = ./visualizer.c\
	   ./read_input.c\
	   ./call_func.c\
	   ./key_press.c\
	   ./moves/s_moves.c\
	   ./moves/p_moves.c\
	   ./moves/r_moves.c\
	   ./moves/rr_moves.c
OBJS = $(SRCS:.c=.o)
INCLUDES = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(FLAGS) $(SRCS) $(INCLUDES) -lmlx -L/usr/X11/lib /usr/X11/lib/libmlx.a -framework OpenGL -framework AppKit

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean, all, re, fclean
