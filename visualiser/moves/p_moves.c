/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:11:26 by nneronin          #+#    #+#             */
/*   Updated: 2021/06/04 16:14:52 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visualiser.h"

void	pa(t_stack *stc)
{
	if (stc->size_b < 0)
		return ;
	stc->size_a += 1;
	stc->a[stc->size_a] = stc->b[stc->size_b];
	stc->b[stc->size_b] = 0;
	stc->size_b -= 1;
}

void	pb(t_stack *stc)
{
	if (stc->size_a < 0)
		return ;
	stc->size_b += 1;
	stc->b[stc->size_b] = stc->a[stc->size_a];
	stc->a[stc->size_a] = 0;
	stc->size_a -= 1;
}
