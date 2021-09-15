/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:31:21 by nneronin          #+#    #+#             */
/*   Updated: 2021/09/15 11:41:12 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	move_reverse(t_stack *stc)
{
	if (stc->cmd[stc->i] == 0)
		sa(stc);
	if (stc->cmd[stc->i] == 1)
		sb(stc);
	if (stc->cmd[stc->i] == 2)
		ss(stc);
	if (stc->cmd[stc->i] == 3)
		pb(stc);
	if (stc->cmd[stc->i] == 4)
		pa(stc);
	if (stc->cmd[stc->i] == 5)
		rra(stc);
	if (stc->cmd[stc->i] == 6)
		rrb(stc);
	if (stc->cmd[stc->i] == 7)
		rrr(stc);
	if (stc->cmd[stc->i] == 8)
		ra(stc);
	if (stc->cmd[stc->i] == 9)
		rb(stc);
	if (stc->cmd[stc->i] == 10)
		rr(stc);
	stc->i -= 1;
}

void	move_forward(t_stack *stc)
{
	stc->i += 1;
	if (stc->cmd[stc->i] == 0)
		sa(stc);
	else if (stc->cmd[stc->i] == 1)
		sb(stc);
	else if (stc->cmd[stc->i] == 2)
		ss(stc);
	else if (stc->cmd[stc->i] == 3)
		pa(stc);
	else if (stc->cmd[stc->i] == 4)
		pb(stc);
	else if (stc->cmd[stc->i] == 5)
		ra(stc);
	else if (stc->cmd[stc->i] == 6)
		rb(stc);
	else if (stc->cmd[stc->i] == 7)
		rr(stc);
	else if (stc->cmd[stc->i] == 8)
		rra(stc);
	else if (stc->cmd[stc->i] == 9)
		rrb(stc);
	else if (stc->cmd[stc->i] == 10)
		rrr(stc);
}
