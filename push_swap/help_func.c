/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:25:31 by nneronin          #+#    #+#             */
/*   Updated: 2021/06/01 15:28:00 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	average(int *i, int size, int x)
{
	int nbr;
	int tmp;

	nbr = 0;
	tmp = 0;
	while (x <= size)
	{
		nbr += i[x];
		x++;
		tmp++;
	}
	return (nbr / tmp);
}

int	find_min_max(int *i, int size, char c)
{
	int	x;
	int	big;

	x = 0;
	big = 0;
	while (x <= size)
	{
		if (c == 'b')
		{
			if (i[big] < i[x])
				big = x;
		}
		else if (c == 's')
		{
			if (i[big] > i[x])
				big = x;
		}
		x++;
	}
	return (big);
}

int	closest(int size, int x)
{
	if (x <= size / 2)
		return (x);
	else
		return (size - x);
}

int	is_s(int *i, int nbr, int size, int x)
{
	while (x <= size)
	{
		if (i[x] < nbr)
			return (-1);
		x++;
	}
	return (0);
}

int	is_b(int *i, int nbr, int size, int x)
{
	while (x <= size)
	{
		if (i[x] > nbr)
			return (-1);
		x++;
	}
	return (0);
}
