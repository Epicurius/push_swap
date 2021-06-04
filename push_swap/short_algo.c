/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:54:11 by nneronin          #+#    #+#             */
/*   Updated: 2021/06/04 15:53:16 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *a, int size)
{
	int	x;

	x = 0;
	while (x < size)
	{
		if (a[x] < a[x + 1])
			return (0);
		x++;
	}
	return (1);
}

int	sort_short(int *a, int *b, t_stack *stc, int s)
{
	int	sml;

	while (stc->size_a > 2)
	{
		sml = a[find_min_max(a, stc->size_a, 's')];
		if (find_min_max(a, stc->size_a, 's') >= stc->size_a / 2)
			while (a[stc->size_a] != sml)
				ra(a, stc, 1);
		else
			while (a[stc->size_a] != sml)
				rra(a, stc, 1);
		pb(a, b, stc);
	}
	while (a[0] < a[1] || a[0] < a[2])
		ra(a, stc, 1);
	if (a[2] > a[1])
		sa(a, stc, 1);
	while (stc->size_b >= 0)
		pa(a, b, stc);
	return (0);
}
