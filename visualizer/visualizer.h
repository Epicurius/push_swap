/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:18:32 by nneronin          #+#    #+#             */
/*   Updated: 2020/03/05 18:01:24 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "mlx.h"
# include "./libft/libft.h"
# define RGB 1
# define START_SIZE 1
# define WIN_WIDTH 900
# define WIN_HIGHT 500

typedef struct		s_stack
{
	int				size_a;
	int				size_b;
	int				i;
	int				m;
	int				k;
	int				moves;
	int				cmd[7000];
	int				*a;
	int				*b;
	void			*win_ptr;
	void			*mlx_ptr;
	int				win_size[2];
	int				x1;
	int				y1;
	int				x2;
}					t_stack;

int					read_input(int ac, char **av, t_stack *stc);
int					ft_isnum(char *str);
void				cordinator(t_stack *stc, int x);
int					ft_cmd(t_stack *stc, char *line);
int					ft_isnum(char *str);
int					key_press(int key, t_stack *stc);
void				fill(t_stack *stc, int x1, int y2, int color);
int					ft_sort(t_stack *stc);
void				print(t_stack *stc, int c);

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
