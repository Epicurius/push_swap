/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:40:20 by nneronin          #+#    #+#             */
/*   Updated: 2021/06/04 16:18:54 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

int	color(int i, float amount)
{
	SDL_Color	s;
	SDL_Color	t;

	amount /= 3;
	if (i >= 0 && i < amount)
	{
		s = (SDL_Color){255, 0, 0};
		t = (SDL_Color){0, 255, 0};
	}
	else if (i >= amount && i < amount * 2)
	{
		i -= amount;
		s = (SDL_Color){0, 255, 0};
		t = (SDL_Color){0, 0, 255};
	}
	else
	{
		i -= amount * 2;
		s = (SDL_Color){0, 0, 255};
		t = (SDL_Color){255, 0, 0};
	}
	return ((s.r + (((t.r - s.r) * i) / (int)amount) & 0xFF) << 16
		| (s.g + (((t.g - s.g) * i) / (int)amount) & 0xFF) << 8
		| (s.b + (((t.b - s.b) * i) / (int)amount) & 0xFF));
}

void	draw_line(SDL_Surface *surf, SDL_Rect r, int total)
{
	int	x;
	int	y;
	int	clr;

	clr = color(r.w, total);
	y = r.y + 1;
	while (--y > r.y - r.h)
	{
		x = r.x - 1;
		while (++x < r.w + r.x)
			((Uint32 *)surf->pixels)[y * surf->w + x] = clr;
	}
}

void	draw(t_stack *stc)
{
	int			i;
	int			max;
	SDL_Rect	a;
	SDL_Rect	b;

	a.x = 0;
	a.y = stc->h;
	a.h = stc->thickness;
	b.x = stc->w / 2;
	b.y = stc->h;
	b.h = stc->thickness;
	i = -1;
	max = ft_max(stc->size_a, stc->size_b);
	while (++i < max)
	{
		a.w = stc->a[i];
		b.w = stc->b[i];
		a.y -= (stc->thickness + 1);
		b.y -= (stc->thickness + 1);
		if (stc->size_a >= i)
			draw_line(stc->surface, a, stc->h / 2);
		if (stc->size_b >= i)
			draw_line(stc->surface, b, stc->h / 2);
	}
}
