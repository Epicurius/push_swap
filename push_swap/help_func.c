/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:25:31 by nneronin          #+#    #+#             */
/*   Updated: 2020/03/05 16:13:51 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			average(int *i, int size, int x)
{
	int		y;
	int		loop;
	double	nbr;
	double	final;

	y = 0;
	loop = 0;
	while (x <= size)
	{
		nbr += i[x];
		loop++;
		if (loop == 2)
		{
			final += nbr / 2;
			loop = 0;
			nbr = 0;
			y++;
		}
		x++;
	}
	final += (loop != 0) ? nbr : 0;
	y += (loop != 0) ? 1 : 0;
	return ((int)final / y);
}

int			find_min_max(int *i, int size, char c)
{
	int x;
	int big;

	x = 0;
	big = 0;
	while (x <= size)
	{
		if (c == 'b')
			i[big] < i[x] ? big = x : 0;
		else if (c == 's')
			i[big] > i[x] ? big = x : 0;
		x++;
	}
	return (big);
}

int			closest(int size, int x)
{
	if (x <= size / 2)
		return (x);
	else
		return (size - x);
}

int			is_s(int *i, int nbr, int size, int x)
{
	while (x <= size)
	{
		if (i[x] < nbr)
			return (-1);
		x++;
	}
	return (0);
}

int			is_b(int *i, int nbr, int size, int x)
{
	while (x <= size)
	{
		if (i[x] > nbr)
			return (-1);
		x++;
	}
	return (0);
}

int			is_sort(int *a, t_stack *stc)
{
	int x;

	x = 0;
	while (x <= stc->size_a)
	{
		if (a[x] < a[x + 1] && x != stc->size_a)
			return (-1);
		x++;
	}
	return (0);
}
