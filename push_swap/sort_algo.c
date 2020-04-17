/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:36:28 by nneronin          #+#    #+#             */
/*   Updated: 2020/03/07 18:19:06 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_a(int *a, int *b, t_stack *stc)
{
	int big;
	int sml;
	int fast;

	while (stc->size_b >= 0)
	{
		big = closest(stc->size_b, find_min_max(b, stc->size_b, 'b'));
		sml = closest(stc->size_b, find_min_max(b, stc->size_b, 's'));
		if (big == 0 && sml == 0)
			big += b[stc->size_b] < b[0] ? 1 : -1;
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

int		push_large_a(int *a, int *b, t_stack *stc)
{
	int avg_b;
	int sml;

	avg_b = average(b, stc->size_b, 0);
	if (stc->size_b >= 200)
		avg_b /= 2;
	while (is_b(b, avg_b, stc->size_b, 0) == -1)
	{
		sml = b[find_min_max(b, stc->size_b, 's')];
		if (b[stc->size_b] == sml && stc->size_b != 0)
		{
			pa(a, b, stc);
			if (!(b[stc->size_b] > avg_b))
				rr(a, b, stc);
			else
				ra(a, stc, 1);
		}
		else if (b[stc->size_b] > avg_b)
			pa(a, b, stc);
		else
			rb(b, stc, 1);
	}
	return (avg_b);
}

void		push_half_b(int *a, int *b, t_stack *stc, int *avg_ab)
{
	int big;

	avg_ab[0] = average(a, stc->size_a, stc->s + 1);
	while (is_s(a, avg_ab[0], stc->size_a, stc->s + 1) == -1)
	{
		if (a[stc->size_a] < avg_ab[0])
			pb(a, b, stc);
		else
		{
			if ((avg_ab[0] / 2) > b[stc->size_b])
				rr(a, b, stc);
			else
				ra(a, stc, 1);
			stc->s += 1;
		}
	}
}

void		push_remain_b(int *a, int *b, t_stack *stc, int *avg_ab)
{
	while (is_s(a, a[stc->size_a], stc->size_a, 0) == -1)
	{
		if (is_s(a, a[stc->size_a], stc->size_a, stc->s + 1) == 0 &&
				is_s(b, a[stc->size_a], stc->size_b, 0) == 0)
		{
			ra(a, stc, 1);
			stc->s += 1;
		}
		else
			pb(a, b, stc);
	}
	avg_ab[0] = -1;
}

int		push_reset(int *a, int *b, t_stack *stc, int *avg_ab)
{
	int s;

	s = find_min_max(a, stc->size_a, 's');
	while (is_s(a, a[stc->size_a], stc->size_a, s + 1) != -1)
	{
		if (is_s(a, a[stc->size_a], stc->size_a, 0) == 0)
			break ;
		ra(a, stc, 1);
		s += 1;
	}
	while (a[stc->size_a] >= avg_ab[1] && a[stc->size_a] <= avg_ab[0])
	{
		if (is_s(a, a[stc->size_a], stc->size_a, s + 1) != -1
				&& is_s(b, a[stc->size_a], stc->size_b, 0) != -1)
		{
			ra(a, stc, 1);
			s += 1;
		}
		else
			pb(a, b, stc);
	}
	return (s);
}

int			sort_algo(int *a, int *b, t_stack *stc)
{
	int big;
	int sml;
	int med;
	int avg_ab[2];

	stc->size_a - stc->s <= 10 ? push_remain_b(a, b, stc, avg_ab) : push_half_b(a, b, stc, avg_ab);
	if (is_s(a, b[0], stc->size_a, 0) == -1)
		while (a[0] > b[0])
			rra(a, stc, 1);
	while (stc->size_b >= 0) // 1
	{
		if (stc->size_b >= 20)
		{
			avg_ab[1] = push_large_a(a, b, stc);
			push_all_a(a, b, stc);
			push_reset(a, b, stc, avg_ab);
		}
		else
		{
			push_all_a(a, b, stc);
			if (avg_ab[0] == -1)
			{
				while (a[stc->size_a] != a[find_min_max(a, stc->size_a, 's')])
					ra(a, stc, 1);
				return (stc->size_a);
			}
			while (a[stc->size_a] < avg_ab[0])
				ra(a, stc, 1);
		}
	}
	return (find_min_max(a, stc->size_a, 's'));
}
