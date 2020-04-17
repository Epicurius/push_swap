/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 09:36:44 by nneronin          #+#    #+#             */
/*   Updated: 2020/03/07 17:32:29 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libft/libft.h"
#include "push_swap.h"
#include "./libft/get_next_line.h"

int		ft_isnum(char *str)
{
	int x;

	x = 0;
	while (str[x])
	{
		if (str[x] == 45 && !(str[x + 1] > 48 && str[x + 1] <= 57))
			return (-1);
		if ((str[x] < 48 || str[x] > 57) && str[x] != 32 && str[x] != 45)
			return (-1);
		if ((str[x] > 48 && str[x] < 57) && str[x + 1] == 45)
			return (-1);
		x++;
	}
	return (0);
}

int		find(char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		x++;
		if (str[x] == ' ')
			return (1);
	}
	return (0);
}

int		count(int ac, char **av, int x, int num)
{
	int y;

	while (x < ac)
	{
		if (ft_isnum(av[x]) == -1)
			return (-1);
		y = 0;
		if (find(av[x]) == 1)
			while (av[x][y])
			{
				while (av[x][y] && av[x][y] == ' ')
					y++;
				if (av[x][y] && av[x][y] != ' ')
				{
					num++;
					while (av[x][y] && av[x][y] != ' ')
						y++;
				}
			}
		else
			num++;
		x++;
	}
	return (num);
}

int		validity(int *a, char *str, t_stack *stc)
{
	long	tmp;
	int		x;

	x = stc->i;
	tmp = ft_atoi(str);
	if (tmp == 0 && stc->zero == 1)
		return (1);
	if (tmp == 0)
		stc->zero = 1;
	if (tmp > 2147483647 || tmp < -2147483648)
		return (1);
	while (x <= stc->size_a && tmp != 0)
	{
		if (a[x] == (int)tmp)
			return (1);
		x++;
	}
	a[stc->i] = (int)tmp;
	stc->i -= 1;
	return (0);
}

int		get_nbr(int ac, char **av, int *a, t_stack *stc)
{
	int		x;
	int		y;
	char	**temp;

	x = 1;
	while (x < ac)
	{
		if (find(av[x]) == 1)
		{
			y = 0;
			temp = ft_strsplit(av[x], ' ');
			while (temp[y] != NULL)
			{
				if (validity(a, temp[y], stc) == 1)
					return (-1);
				y += 1;
			}
		}
		else if (validity(a, av[x], stc) == 1)
			return (-1);
		x += 1;
	}
	return (0);
}

int		read_input(int ac, char **av, t_stack *stc)
{
	int		*a;
	int		*b;
	int		c;

	if ((c = count(ac, av, 1, 0)) == -1)
		return (-1);
	a = (int *)malloc(sizeof(int) * c);
	b = (int *)malloc(sizeof(int) * c);
	stc->i = c - 1;
	stc->size_a = c - 1;
	stc->size_b = -1;
	if ((get_nbr(ac, av, a, stc)) == -1)
		return (-1);
	stc->s = -1;
	if (ft_sort(a, stc->size_a) == 0)
		return (0);
	if (c <= 10)
		sort_short(a, b, stc, 0);
	else
	{
		while (is_sort(a, stc) == -1)
			stc->s = sort_algo(a, b, stc);
	}
	return (0);
}
