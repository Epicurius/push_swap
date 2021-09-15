/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:18:32 by nneronin          #+#    #+#             */
/*   Updated: 2021/09/15 11:41:12 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef visualizer_H
# define visualizer_H

# include "libft.h"
# include "libpf.h"
# include "SDL.h"
# include "SDL_ttf.h"

typedef struct s_stack
{
	SDL_Surface		*surface;
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	int				*a;
	int				*b;
	int				size_a;
	int				size_b;
	int				*cmd;
	int				moves;
	int				quit;
	int				pause;
	int				w;
	int				h;
	int				thickness;
	int				i;
}					t_stack;

void				update_screen(t_stack *stc);
void				keys(t_stack *stc, SDL_Event *event);
void				init_sdl(t_stack *stc);
void				free_vis(t_stack *stc);
void				error_msg(const char *restrict format, ...);
int					ft_isnum(char *str);
int					read_input(int ac, char **av, t_stack *stc);
void				draw(t_stack *stc);
void				move_forward(t_stack *stc);
void				move_reverse(t_stack *stc);
void				sa(t_stack *stc);
void				sb(t_stack *stc);
void				ss(t_stack *stc);
void				pa(t_stack *stc);
void				pb(t_stack *stc);
void				ra(t_stack *stc);
void				rb(t_stack *stc);
void				rr(t_stack *stc);
void				rra(t_stack *stc);
void				rrb(t_stack *stc);
void				rrr(t_stack *stc);

#endif
