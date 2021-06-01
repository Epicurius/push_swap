/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:10:21 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/31 10:19:28 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	largest_to_a(int *a, int *b, t_stack *stc)
{
	int	l;

	l = b[find_min_max(b, stc->size_b, 'b')];
	if (find_min_max(b, stc->size_b, 'b') <= (stc->size_b / 2))
	{
		while (b[stc->size_b] != l)
			rrb(b, stc, 1);
	}
	else
	{
		while (b[stc->size_b] != l)
			rb(b, stc, 1);
	}
}

void	smallest_to_a(int *a, int *b, t_stack *stc)
{
	int	s;

	s = b[find_min_max(b, stc->size_b, 's')];
	if (find_min_max(b, stc->size_b, 's') >= (stc->size_b / 2))
	{
		while (b[stc->size_b] != s)
			rb(b, stc, 1);
	}
	else
	{
		while (b[stc->size_b] != s)
			rrb(b, stc, 1);
	}
}
