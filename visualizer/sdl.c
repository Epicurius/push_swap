/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:09:56 by nneronin          #+#    #+#             */
/*   Updated: 2021/06/01 20:35:01 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	update_screen(t_stack *stc)
{
	if (SDL_UpdateTexture(stc->texture, NULL, stc->surface->pixels,
			stc->surface->pitch))
		error_msg("Failed to update screen: %s\n", SDL_GetError());
	if (SDL_RenderCopy(stc->renderer, stc->texture, NULL, NULL))
		error_msg("SDL_RenderCopy error: %s\n", SDL_GetError());
	SDL_RenderPresent(stc->renderer);
}

void	keys(t_stack *stc, SDL_Event *event)
{
	if (event->type == SDL_QUIT)
		stc->quit = 1;
	if (event->type == SDL_KEYDOWN)
	{
		if (event->key.keysym.sym == SDLK_q
			|| event->key.keysym.sym == SDLK_ESCAPE)
			stc->quit = 1;
		else if (event->key.keysym.sym == SDLK_f
				&& stc->pause == 1 && stc->i < stc->moves - 1)
			move_forward(stc);
		else if (event->key.keysym.sym == SDLK_r
				&& stc->pause == 1 && stc->i > 0)
			move_reverse(stc);
		else if (event->key.keysym.sym == SDLK_p)
			stc->pause = stc->pause == 0;
	}
}

void	init_sdl(t_stack *stc)
{
	SDL_DisplayMode dm;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
		error_msg("Could not init SDL: %s\n", SDL_GetError());
	SDL_GetCurrentDisplayMode(0, &dm);
	if (dm.w <= stc->w || dm.h <= stc->h)
		error_msg("To many values ot to llarge values");
	if (TTF_Init())
		error_msg("Could not init TTF: %s\n", SDL_GetError());
	stc->win = SDL_CreateWindow("Visualiser", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, stc->w, stc->h, SDL_WINDOW_ALWAYS_ON_TOP);
	if (!stc->win)
		error_msg("Could not create window: %s\n", SDL_GetError());
	stc->surface = SDL_CreateRGBSurfaceWithFormat(0, stc->w, stc->h,
			32, SDL_PIXELFORMAT_ARGB8888);
	if (!stc->surface)
		error_msg("Could not create surface: %s\n", SDL_GetError());
	stc->renderer = SDL_CreateRenderer(stc->win, -1,
			SDL_RENDERER_TARGETTEXTURE);
	if (!stc->renderer)
		error_msg("Could not create renderer: %s\n", SDL_GetError());
	stc->texture = SDL_CreateTexture(stc->renderer, SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STREAMING, stc->surface->w, stc->surface->h);
	if (!stc->texture)
		error_msg("Could not create texture: %s\n", SDL_GetError());
}

void	free_vis(t_stack *stc)
{
	if (stc->a)
		free(stc->a);
	if (stc->b)
		free(stc->b);
	SDL_FreeSurface(stc->surface);
	SDL_DestroyTexture(stc->texture);
	SDL_DestroyRenderer(stc->renderer);
	SDL_DestroyWindow(stc->win);
	SDL_Quit();
	TTF_Quit();
	free(stc);
}
