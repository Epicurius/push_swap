/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:41:43 by nneronin          #+#    #+#             */
/*   Updated: 2020/03/05 16:09:27 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		sa(int *a, t_stack *stc, int p)
{
	int tmp;

	if (stc->size_a < 1)
		return ;
	tmp = a[stc->size_a];
	a[stc->size_a] = a[stc->size_a - 1];
	a[stc->size_a - 1] = tmp;
	if (p == 1)
		write(1, "sa\n", 3);
}

void		sb(int *b, t_stack *stc, int p)
{
	int tmp;

	if (stc->size_b < 1)
		return ;
	tmp = b[stc->size_b];
	b[stc->size_b] = b[stc->size_b - 1];
	b[stc->size_b - 1] = tmp;
	if (p == 1)
		write(1, "sb\n", 3);
}

void		ss(int *a, int *b, t_stack *stc)
{
	if (stc->size_a > 0)
		sa(a, stc, 0);
	if (stc->size_b > 0)
		sb(b, stc, 0);
	write(1, "ss\n", 3);
}
