/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:12:21 by nneronin          #+#    #+#             */
/*   Updated: 2020/03/05 16:04:59 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		ra(int *a, t_stack *stc, int p)
{
	int y;
	int tmp;

	y = stc->size_a;
	tmp = a[y];
	while (y--)
		a[y + 1] = a[y];
	a[0] = tmp;
	if (p == 1)
		write(1, "ra\n", 3);
}

void		rb(int *b, t_stack *stc, int p)
{
	int y;
	int tmp;

	y = stc->size_b;
	tmp = b[y];
	while (y--)
		b[y + 1] = b[y];
	b[0] = tmp;
	if (p == 1)
		write(1, "rb\n", 3);
}

void		rr(int *a, int *b, t_stack *stc)
{
	if (stc->size_a > 0)
		ra(a, stc, 0);
	if (stc->size_b > 0)
		rb(b, stc, 0);
	write(1, "rr\n", 3);
}
