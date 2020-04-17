/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:13:21 by nneronin          #+#    #+#             */
/*   Updated: 2020/03/05 14:50:07 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visualizer.h"

void		rra(t_stack *stc)
{
	int x;
	int y;
	int tmp;

	x = -1;
	y = stc->size_a;
	tmp = stc->a[0];
	while (x++ < y)
		stc->a[x] = stc->a[x + 1];
	stc->a[stc->size_a] = tmp;
}

void		rrb(t_stack *stc)
{
	int x;
	int y;
	int tmp;

	x = -1;
	y = stc->size_b;
	tmp = stc->b[0];
	while (x++ < y)
		stc->b[x] = stc->b[x + 1];
	stc->b[stc->size_b] = tmp;
}

void		rr(t_stack *stc)
{
	if (stc->size_a > 0)
		ra(stc);
	if (stc->size_b > 0)
		rb(stc);
}
