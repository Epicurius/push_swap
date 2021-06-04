/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:36:28 by nneronin          #+#    #+#             */
/*   Updated: 2021/06/04 16:05:46 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_remaining_a(int *a, int *b, t_stack *stc)
{
	push_large_a(a, b, stc);
	push_all_a(a, b, stc);
	push_reset(a, b, stc);
}

void	sort_algo(int *a, int *b, t_stack *stc)
{
	if (stc->size_a - stc->s <= 10 && stc->size_a != -1)
		push_remain_b(a, b, stc);
	else
		push_half_b(a, b, stc);
	if (is_s(a, b[0], stc->size_a, 0) == -1)
		while (a[0] > b[0])
			rra(a, stc, 1);
	while (stc->size_b >= 0)
	{
		if (stc->size_b >= 20)
			push_remaining_a(a, b, stc);
		else
		{
			push_all_a(a, b, stc);
			if (stc->avg_a == -1)
			{
				while (a[stc->size_a] != a[find_min_max(a, stc->size_a, 's')])
					ra(a, stc, 1);
				return ;
			}
			while (a[stc->size_a] < stc->avg_a)
				ra(a, stc, 1);
		}
	}
}
