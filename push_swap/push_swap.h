/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:18:32 by nneronin          #+#    #+#             */
/*   Updated: 2020/03/07 11:35:47 by nneronin         ###   ########.fr       */
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
	int				s;
	int				zero;
}					t_stack;

void				print(int *a, int *b, t_stack *stc, int ac);
int					ft_sort(int *a, int size);
int					read_input(int ac, char **av, t_stack *stc);

int					sort_algo(int *a, int *b, t_stack *stc);
int					sort_short(int *a, int *b, t_stack *stc, int s);
void				largest_to_a(int *a, int *b, t_stack *stc);
void				smallest_to_a(int *a, int *b, t_stack *stc);
void				print(int *a, int *b, t_stack *stc, int ac);
int					average(int *i, int size, int x);
int					find_min_max(int *i, int size, char c);
int					closest(int size, int x);
int					is_s(int *i, int nbr, int size, int x);
int					is_b(int *i, int nbr, int size, int x);
int					is_sort(int *a, t_stack *stc);

void				sa(int *a, t_stack *stc, int p);
void				sb(int *b, t_stack *stc, int p);
void				ss(int *a, int *b, t_stack *stc);
void				pa(int *a, int *b, t_stack *stc);
void				pb(int *a, int *b, t_stack *stc);
void				ra(int *a, t_stack *stc, int p);
void				rb(int *b, t_stack *stc, int p);
void				rr(int *a, int *b, t_stack *stc);
void				rra(int *a, t_stack *stc, int p);
void				rrb(int *b, t_stack *stc, int p);
void				rrr(int *a, int *b, t_stack *stc);

#endif
