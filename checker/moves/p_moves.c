/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:11:26 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/31 11:03:27 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	pa(int *a, int *b, t_stack *stc)
{
	if (stc->size_b < 0)
		return ;
	stc->size_a += 1;
	a[stc->size_a] = b[stc->size_b];
	b[stc->size_b] = 0;
	stc->size_b -= 1;
}

void	pb(int *a, int *b, t_stack *stc)
{
	if (stc->size_a < 0)
		return ;
	stc->size_b += 1;
	b[stc->size_b] = a[stc->size_a];
	a[stc->size_a] = 0;
	stc->size_a -= 1;
}
