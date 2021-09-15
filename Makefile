# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/04 16:29:48 by nneronin          #+#    #+#              #
#    Updated: 2021/09/15 11:41:12 by nneronin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED				:= "\e[0;31m"
GREEN			:= "\e[0;32m"
YELLOW			:= "\e[0;33m"
BLUE			:= "\e[0;34m"
MAGENTA			:= "\e[0;35m"
CYAN			:= "\e[0;36m"
RESET			:= "\e[0m"

all:
	@make -C ./checker
	@make -C ./push_swap
	@make -C ./visualizer

clean:
	@make -C ./checker clean
	@make -C ./push_swap clean
	@make -C ./visualizer clean

fclean: clean
	@make -C ./checker fclean
	@make -C ./push_swap fclean
	@make -C ./visualizer fclean

re: fclean all

.PHONY: clean, all, re, fclean
