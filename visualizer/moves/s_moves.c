/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:41:43 by nneronin          #+#    #+#             */
/*   Updated: 2021/09/15 11:41:12 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visualizer.h"

void	sa(t_stack *stc)
{
	int	tmp;

	if (stc->size_a < 1)
		return ;
	tmp = stc->a[stc->size_a];
	stc->a[stc->size_a] = stc->a[stc->size_a - 1];
	stc->a[stc->size_a - 1] = tmp;
}

void	sb(t_stack *stc)
{
	int	tmp;

	if (stc->size_b < 1)
		return ;
	tmp = stc->b[stc->size_b];
	stc->b[stc->size_b] = stc->b[stc->size_b - 1];
	stc->b[stc->size_b - 1] = tmp;
}

void	ss(t_stack *stc)
{
	if (stc->size_a > 0)
		sa(stc);
	if (stc->size_b > 0)
		sb(stc);
}
