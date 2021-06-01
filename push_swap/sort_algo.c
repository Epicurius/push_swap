/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:36:28 by nneronin          #+#    #+#             */
/*   Updated: 2021/06/01 15:36:44 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

void	push_all_a(int *a, int *b, t_stack *stc)
{
	int	big;
	int	sml;

	while (stc->size_b >= 0)
	{
		big = closest(stc->size_b, find_min_max(b, stc->size_b, 'b'));
		sml = closest(stc->size_b, find_min_max(b, stc->size_b, 's'));
		if (big == 0 && sml == 0 && b[stc->size_b] < b[0])
			big += 1;
		else if (big == 0 && sml == 0 && b[stc->size_b] >= b[0])
			big -= 1;
		if (sml - 1 < big)
		{
			smallest_to_a(a, b, stc);
			pa(a, b, stc);
			ra(a, stc, 1);
		}
		else
		{
			largest_to_a(a, b, stc);
			pa(a, b, stc);
		}
	}
}

void	push_large_a(int *a, int *b, t_stack *stc)
{
	stc->avg_b = average(b, stc->size_b, 0);
	if (stc->size_b >= 200)
		stc->avg_b = stc->avg_b / 2;
	while (is_b(b, stc->avg_b, stc->size_b, 0) == -1)
	{
		if (b[stc->size_b] > stc->avg_b)
			pa(a, b, stc);
		else
			rb(b, stc, 1);
	}
}

void	push_half_b(int *a, int *b, t_stack *stc)
{
	stc->avg_a = average(a, stc->size_a, stc->s + 1);
	while (is_s(a, stc->avg_a, stc->size_a, stc->s + 1) == -1)
	{
		if (a[stc->size_a] < stc->avg_a)
			pb(a, b, stc);
		else
		{
			//if ((stc->avg_a / 2) > b[stc->size_b])
			//	rr(a, b, stc);
			//else
				ra(a, stc, 1);
			stc->s += 1;
		}
	}
}

void	push_remain_b(int *a, int *b, t_stack *stc)
{
	while (is_s(a, a[stc->size_a], stc->size_a, 0) == -1)
	{
		if (!is_s(a, a[stc->size_a], stc->size_a, stc->s + 1)
			&& !is_s(b, a[stc->size_a], stc->size_b, 0))
		{
			ra(a, stc, 1);
			stc->s += 1;
		}
		else
			pb(a, b, stc);
	}
	stc->avg_a = -1;
}

//	was not stc->s but int s before
void	push_reset(int *a, int *b, t_stack *stc)
{
	stc->s = find_min_max(a, stc->size_a, 's');
	while (is_s(a, a[stc->size_a], stc->size_a, stc->s + 1) != -1)
	{
		if (is_s(a, a[stc->size_a], stc->size_a, 0) == 0)
			break ;
		ra(a, stc, 1);
		stc->s += 1;
	}
	while (a[stc->size_a] >= stc->avg_b && a[stc->size_a] <= stc->avg_a)
	{
		if (is_s(a, a[stc->size_a], stc->size_a, stc->s + 1) != -1
			&& is_s(b, a[stc->size_a], stc->size_b, 0) != -1)
		{
			ra(a, stc, 1);
			stc->s += 1;
		}
		else
			pb(a, b, stc);
	}
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
		{
			push_large_a(a, b, stc);
			push_all_a(a, b, stc);
			push_reset(a, b, stc);
		}
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
