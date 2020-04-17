/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:13:21 by nneronin          #+#    #+#             */
/*   Updated: 2020/03/05 16:04:52 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		rra(int *a, t_stack *stc, int p)
{
	int x;
	int y;
	int tmp;

	x = -1;
	y = stc->size_a;
	tmp = a[0];
	while (x++ < y)
		a[x] = a[x + 1];
	a[stc->size_a] = tmp;
	if (p == 1)
		write(1, "rra\n", 4);
}

void		rrb(int *b, t_stack *stc, int p)
{
	int x;
	int y;
	int tmp;

	x = -1;
	y = stc->size_b;
	tmp = b[0];
	while (x++ < y)
		b[x] = b[x + 1];
	b[stc->size_b] = tmp;
	if (p == 1)
		write(1, "rrb\n", 4);
}

void		rrr(int *a, int *b, t_stack *stc)
{
	if (stc->size_a > 0)
		rra(a, stc, 0);
	if (stc->size_b > 0)
		rrb(b, stc, 0);
	write(1, "rrr\n", 4);
}
