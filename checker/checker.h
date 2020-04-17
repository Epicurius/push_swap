/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:18:32 by nneronin          #+#    #+#             */
/*   Updated: 2020/03/05 18:40:01 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./libft/libft.h"

typedef struct		s_stack
{
	int				size_a;
	int				size_b;
	int				i;
	int				moves;
	int				debug;
	int				zero;
}					t_stack;

void				print(int *a, int *b, t_stack *stc, int ac);
int					ft_sort(int *a, int x);
int					read_input(int ac, char **av, t_stack *stc);
int					ft_isnum(char *str);
void				cordinator(int *a, int *b, t_stack *stc, int x);
int					ft_cmd(int *a, int *b, t_stack *stc, char *line);

void				sa(int *a, t_stack *stc);
void				sb(int *b, t_stack *stc);
void				ss(int *a, int *b, t_stack *stc);
void				pa(int *a, int *b, t_stack *stc);
void				pb(int *a, int *b, t_stack *stc);
void				ra(int *a, t_stack *stc);
void				rb(int *b, t_stack *stc);
void				rr(int *a, int *b, t_stack *stc);
void				rra(int *a, t_stack *stc);
void				rrb(int *b, t_stack *stc);
void				rrr(int *a, int *b, t_stack *stc);

#endif
