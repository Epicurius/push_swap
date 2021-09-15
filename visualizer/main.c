/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:07:40 by nneronin          #+#    #+#             */
/*   Updated: 2021/09/15 11:41:12 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int	ft_isnum(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] == 45 && !(str[x + 1] > 48 && str[x + 1] <= 57))
			return (0);
		if ((str[x] < 48 || str[x] > 57) && str[x] != 32 && str[x] != 45)
			return (0);
		if ((str[x] > 48 && str[x] < 57) && str[x + 1] == 45)
			return (0);
		x++;
	}
	return (1);
}

void	draw_loop(t_stack *stc)
{
	SDL_Event	event;

	while (!stc->quit)
	{
		while (SDL_PollEvent(&event))
			keys(stc, &event);
		if (!stc->pause && stc->i < stc->moves - 1)
			move_forward(stc);
		SDL_FillRect(stc->surface, NULL, 0xFF363636);
		draw(stc);
		update_screen(stc);
	}
}

int	main(int ac, char **av)
{
	t_stack		*stc;

	if (ac <= 1)
		error_msg("No args passed.");
	stc = ft_memalloc(sizeof(t_stack));
	stc->w = 0;
	if (!read_input(ac, av, stc))
		error_msg("On input.");
	stc->w = ft_max(480, stc->w * 2 + 1);
	stc->h = ft_max(720, stc->size_a * 2 + 10);
	stc->thickness = 1;
	if (stc->h == 720)
		stc->thickness = floor((720 - stc->size_a) / stc->size_a);
	init_sdl(stc);
	SDL_FillRect(stc->surface, NULL, 0xFF363636);
	stc->i = -1;
	stc->pause = 1;
	draw(stc);
	draw_loop(stc);
	free_vis(stc);
	return (0);
}
