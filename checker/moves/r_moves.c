/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:13:21 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/31 11:03:48 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	rra(int *a, t_stack *stc)
{
	int	x;
	int	y;
	int	tmp;

	x = -1;
	y = stc->size_a;
	tmp = a[0];
	while (x++ < y)
		a[x] = a[x + 1];
	a[stc->size_a] = tmp;
}

void	rrb(int *b, t_stack *stc)
{
	int	x;
	int	y;
	int	tmp;

	x = -1;
	y = stc->size_b;
	tmp = b[0];
	while (x++ < y)
		b[x] = b[x + 1];
	b[stc->size_b] = tmp;
}

void	rr(int *a, int *b, t_stack *stc)
{
	if (stc->size_a > 0)
		ra(a, stc);
	if (stc->size_b > 0)
		rb(b, stc);
}
