/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:55:30 by nneronin          #+#    #+#             */
/*   Updated: 2020/03/05 18:18:37 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void		forward(t_stack *stc)
{
	print(stc, 0x000000);
	stc->k += 1;
	cordinator(stc, stc->cmd[stc->k]);
	print(stc, 0x00ff00);
	fill(stc, 80, 80, 0x000000);
	mlx_string_put(stc->mlx_ptr, stc->win_ptr, 0, 20, 0xFFFF00, "Moves:");
	mlx_string_put(stc->mlx_ptr,
		stc->win_ptr, 0, 50, 0xFFFF00, ft_itoa(stc->k));
}

void		backward(t_stack *stc)
{
	int x;

	print(stc, 0x000000);
	if (stc->cmd[stc->k] == 1 || stc->cmd[stc->k] == 0)
		x = stc->cmd[stc->k] == 0 ? 1 : 0;
	else if (stc->cmd[stc->k] == 3 || stc->cmd[stc->k] == 4)
		x = stc->cmd[stc->k] == 3 ? 4 : 3;
	else if (stc->cmd[stc->k] == 5 || stc->cmd[stc->k] == 6)
		x = stc->cmd[stc->k] == 5 ? 6 : 5;
	else if (stc->cmd[stc->k] == 8 || stc->cmd[stc->k] == 9)
		x = stc->cmd[stc->k] == 8 ? 9 : 8;
	else if (stc->cmd[stc->k] == 7 || stc->cmd[stc->k] == 10)
		x = stc->cmd[stc->k] == 7 ? 10 : 7;
	else
		x = 2;
	stc->k -= 1;
	cordinator(stc, x);
	print(stc, 0x00ff00);
	fill(stc, 80, 80, 0x000000);
	mlx_string_put(stc->mlx_ptr, stc->win_ptr, 0, 20, 0xFFFF00, "Moves:");
	mlx_string_put(stc->mlx_ptr,
			stc->win_ptr, 0, 50, 0xFFFF00, ft_itoa(stc->k));
}

int			key_press(int key, t_stack *stc)
{
	key == 53 ? exit(0) : 0;
	if (stc->m == stc->k)
		return (0);
	if (stc->m - 1 <= stc->k)
	{
		mlx_string_put(stc->mlx_ptr,
				stc->win_ptr, 0, 80, 0x00ffff, "DONE!");
		ft_sort(stc) == 0 ? mlx_string_put(stc->mlx_ptr, stc->win_ptr,
				0, 110, 0x00ffff, "SORTED!") : mlx_string_put(stc->mlx_ptr,
					stc->win_ptr, 0, 110, 0x00ffff, "FUCKED!");
		stc->k += 1;
		return (0);
	}
	else if (key == 49)
		forward(stc);
	else if (key == 51 && stc->k > 0)
		backward(stc);
	return (0);
}
