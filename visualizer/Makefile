# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/29 14:37:29 by nneronin          #+#    #+#              #
#    Updated: 2021/09/15 11:41:12 by nneronin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL_NAME	:= $(shell uname -s)

RED				:= "\e[0;31m"
GREEN			:= "\e[0;32m"
YELLOW			:= "\e[0;33m"
BLUE			:= "\e[0;34m"
MAGENTA			:= "\e[0;35m"
CYAN			:= "\e[0;36m"
RESET			:= "\e[0m"

NAME			= visualizer

SDL_DIR			:= ./SDL
SDL_MAIN		:= -I $(SDL_DIR)/SDL2.framework/Headers -framework SDL2 -F $(SDL_DIR)
SDL_TTF			:= -I $(SDL_DIR)/SDL2_ttf.framework/Headers -framework SDL2_ttf -F $(SDL_DIR)

LIB_DIR			:= ../lib
LIBFT			:= -I $(LIB_DIR)/libft $(LIB_DIR)/libft/libft.a
LIBPF			:= -I $(LIB_DIR)/libpf $(LIB_DIR)/libpf/libpf.a

LIBS			+= $(SDL_MAIN) $(SDL_TTF) $(LIBFT) $(LIBPF)
CFLAGS			:= -Wall -Wextra -Werror

SRCS =	./main.c\
		./read_input.c\
		./error_msg.c\
		./draw.c\
		./moves.c\
		./moves/p_moves.c\
		./moves/r_moves.c\
		./moves/rr_moves.c\
		./moves/s_moves.c\
		./sdl.c

OBJ = $(SRCS:.c=.o)

all: framework libs $(NAME)
	@printf $(GREEN)"$(NAME) ready!\n"$(RESET)

$(NAME):
	@printf $(CYAN)"[INFO]	Compiling $(NAME)\n"$(RESET)
	@gcc -o $(NAME) $(SRCS) $(LIBS)

libs: $(LIB_DIR)
	@make -C ../lib/libft
	@make -C ../lib/libpf
	@printf $(CYAN)"[INFO]	All libs compiled.\n"$(RESET)

clean:
	@printf $(CYAN)"[INFO]	Deleted objects\n"$(RESET)
	@/bin/rm -rf $(OBJS)

fclean: clean
	@printf $(CYAN)"[INFO]	Deleted $(NAME)\n"$(RESET)
	@/bin/rm -f $(NAME)

framework:
ifeq ($(SHELL_NAME), Darwin)
	@mkdir -p ~/Library/Frameworks	
ifeq ("$(wildcard ~/Library/Frameworks/SDL2*.framework)","")
	@cp -Rf $(SDL_DIR)/SDL2.framework ~/Library/Frameworks/
	@cp -Rf $(SDL_DIR)/SDL2_ttf.framework ~/Library/Frameworks/
	@printf $(CYAN)"[INFO]	Moving Frameworks\n"$(RESET)
else
	@printf $(CYAN)"[INFO]	Frameworks Exists\n"$(RESET)
endif
endif

framework_del:
	@rm -rf ~/Library/Frameworks/SDL2*.framework
	@/bin/rm -f $(NAME)
	@printf $(CYAN)"[INFO]	Deleted SDL2 Frameworks from ~/Library/Frameworks\n"$(RESET)

framework_re: framework_del
	@cp -Rf $(SDL_DIR)/SDL2.framework ~/Library/Frameworks/
	@cp -Rf $(SDL_DIR)/SDL2_ttf.framework ~/Library/Frameworks/
	@printf $(CYAN)"[INFO]	Mooving SDL2 Frameworks to ~/Library/Frameworks\n"$(RESET)

re: fclean all

.PHONY: clean, all, re, fclean, framework, framework_del, frameworks_re
