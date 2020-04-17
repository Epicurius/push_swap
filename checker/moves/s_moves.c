/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:41:43 by nneronin          #+#    #+#             */
/*   Updated: 2020/03/05 15:54:15 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void		sa(int *a, t_stack *stc)
{
	int tmp;

	if (stc->size_a < 1)
		return ;
	tmp = a[stc->size_a];
	a[stc->size_a] = a[stc->size_a - 1];
	a[stc->size_a - 1] = tmp;
}

void		sb(int *b, t_stack *stc)
{
	int tmp;

	if (stc->size_b < 1)
		return ;
	tmp = b[stc->size_b];
	b[stc->size_b] = b[stc->size_b - 1];
	b[stc->size_b - 1] = tmp;
}

void		ss(int *a, int *b, t_stack *stc)
{
	if (stc->size_a > 0)
		sa(a, stc);
	if (stc->size_b > 0)
		sb(b, stc);
}
