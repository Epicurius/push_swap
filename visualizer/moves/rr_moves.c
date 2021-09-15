/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:12:21 by nneronin          #+#    #+#             */
/*   Updated: 2021/09/15 11:41:12 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visualizer.h"

void	ra(t_stack *stc)
{
	int	y;
	int	tmp;

	y = stc->size_a;
	tmp = stc->a[y];
	while (y--)
		stc->a[y + 1] = stc->a[y];
	stc->a[0] = tmp;
}

void	rb(t_stack *stc)
{
	int	y;
	int	tmp;

	y = stc->size_b;
	tmp = stc->b[y];
	while (y--)
		stc->b[y + 1] = stc->b[y];
	stc->b[0] = tmp;
}

void	rrr(t_stack *stc)
{
	if (stc->size_a > 0)
		rra(stc);
	if (stc->size_b > 0)
		rrb(stc);
}
