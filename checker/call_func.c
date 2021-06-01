/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:26:01 by nneronin          #+#    #+#             */
/*   Updated: 2021/06/01 15:39:36 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_free(char **temp)
{
	int	x;

	x = 0;
	while (x <= 10)
	{
		ft_strdel(&temp[x]);
		x++;
	}
	free(temp);
}

void	cordinator(int *a, int *b, t_stack *stc, int x)
{
	if (x == 0)
		sa(a, stc);
	else if (x == 1)
		sb(b, stc);
	else if (x == 2)
		ss(a, b, stc);
	else if (x == 3)
		pa(a, b, stc);
	else if (x == 4)
		pb(a, b, stc);
	else if (x == 5)
		ra(a, stc);
	else if (x == 6)
		rb(b, stc);
	else if (x == 7)
		rr(a, b, stc);
	else if (x == 8)
		rra(a, stc);
	else if (x == 9)
		rrb(b, stc);
	else if (x == 10)
		rrr(a, b, stc);
	stc->moves += 1;
}

int	ft_cmd(int *a, int *b, t_stack *stc, char *line)
{
	int		x;
	char	**temp;

	x = -1;
	temp = ft_strsplit("sa sb ss pa pb ra rb rr rra rrb rrr", ' ', NULL);
	while (++x <= 10)
	{
		if (ft_strcmp(temp[x], line) == 0)
		{
			cordinator(a, b, stc, x);
			free(temp);
			return (x);
		}
	}
	free(temp);
	return (-1);
}

int	ft_isnum(char *str)
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
