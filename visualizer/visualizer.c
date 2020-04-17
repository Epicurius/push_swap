/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:10:51 by nneronin          #+#    #+#             */
/*   Updated: 2020/03/05 17:56:01 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "visualizer.h"

int			ft_sort(t_stack *stc)
{
	int x;

	x = 0;
	while (x <= stc->size_a)
	{
		if (stc->a[x] < stc->a[x + 1] && x != stc->size_a)
			return (-1);
		x++;
	}
	return (0);
}

void		fill(t_stack *stc, int x1, int y2, int color)
{
	int x;
	int y;

	y = 0;
	while (y <= y2)
	{
		x = 0;
		while (x++ <= x1)
			mlx_pixel_put(stc->mlx_ptr, stc->win_ptr, x, y, color);
		y++;
	}
}

void		print(t_stack *stc, int c)
{
	int y;
	int a_count;
	int b_count;

	y = 0;
	a_count = 1;
	b_count = 1;
	while (y <= (stc->size_a > stc->size_b ? stc->size_a : stc->size_b))
	{
		stc->x1 = 100;
		stc->y1 = (WIN_HIGHT - 10) - (a_count * 5);
		stc->size_a >= y ? a_count += 1 : 0;
		if (stc->size_a >= y)
			while (stc->x1++ < (stc->a[y] * 2) + 100)
				mlx_pixel_put(stc->mlx_ptr, stc->win_ptr, stc->x1, stc->y1, c);
		stc->x1 = 650;
		stc->y1 = (WIN_HIGHT - 10) - (b_count * 5);
		stc->size_b >= y ? b_count += 1 : 0;
		if (stc->size_b >= y)
			while (stc->x1++ < (stc->b[y] * 2) + 650)
				mlx_pixel_put(stc->mlx_ptr, stc->win_ptr, stc->x1, stc->y1, c);
		y++;
	}
}

int			main(int ac, char **av)
{
	t_stack		*stc;

	if (ac <= 1)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	stc = (t_stack *)malloc(sizeof(t_stack));
	stc->k = -1;
	stc->win_size[0] = WIN_WIDTH;
	stc->win_size[1] = WIN_HIGHT;
	stc->m = 0;
	stc->mlx_ptr = mlx_init();
	stc->win_ptr = mlx_new_window(
			stc->mlx_ptr, stc->win_size[0], stc->win_size[1], "Visualizer");
	stc->moves = 0;
	stc->size_b = -1;
	read_input(ac, av, stc);
	print(stc, 0x00ff00);
	mlx_hook(stc->win_ptr, 2, 0, key_press, stc);
	mlx_loop(stc->mlx_ptr);
	return (0);
}
