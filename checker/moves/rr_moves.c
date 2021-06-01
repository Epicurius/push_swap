/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:12:21 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/31 11:04:08 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ra(int *a, t_stack *stc)
{
	int	y;
	int	tmp;

	y = stc->size_a;
	tmp = a[y];
	while (y--)
		a[y + 1] = a[y];
	a[0] = tmp;
}

void	rb(int *b, t_stack *stc)
{
	int	y;
	int	tmp;

	y = stc->size_b;
	tmp = b[y];
	while (y--)
		b[y + 1] = b[y];
	b[0] = tmp;
}

void	rrr(int *a, int *b, t_stack *stc)
{
	if (stc->size_a > 0)
		rra(a, stc);
	if (stc->size_b > 0)
		rrb(b, stc);
}
