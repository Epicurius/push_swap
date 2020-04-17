/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:26:01 by nneronin          #+#    #+#             */
/*   Updated: 2020/03/05 15:38:53 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "visualizer.h"

void		ft_free(char **temp)
{
	int x;

	x = 0;
	while (x <= 10)
	{
		ft_strdel(&temp[x]);
		x++;
	}
	free(temp);
}

void		cordinator(t_stack *stc, int x)
{
	if (x == 0)
		sa(stc);
	else if (x == 1)
		sb(stc);
	else if (x == 2)
		ss(stc);
	else if (x == 3)
		pa(stc);
	else if (x == 4)
		pb(stc);
	else if (x == 5)
		ra(stc);
	else if (x == 6)
		rb(stc);
	else if (x == 7)
		rr(stc);
	else if (x == 8)
		rra(stc);
	else if (x == 9)
		rrb(stc);
	else if (x == 10)
		rrr(stc);
	stc->moves += 1;
}

int			ft_cmd(t_stack *stc, char *line)
{
	int		x;
	char	**temp;

	x = 0;
	temp = ft_strsplit("sa sb ss pa pb ra rb rr rra rrb rrr", ' ');
	while (x <= 10)
	{
		if (ft_strcmp(temp[x], line) == 0)
		{
			stc->cmd[stc->m] = x;
			stc->m += 1;
			ft_free(temp);
			return (x);
		}
		x++;
	}
	x = 0;
	ft_free(temp);
	return (-1);
}

int			ft_isnum(char *str)
{
	int x;

	x = 0;
	while (str[x])
	{
		if (str[x] == 45 && !(str[x + 1] > 48 && str[x + 1] < 57))
			return (-1);
		if ((str[x] < 48 || str[x] > 57) && str[x] != 32 && str[x] != 45)
			return (-1);
		if ((str[x] > 48 && str[x] < 57) && str[x + 1] == 45)
			return (-1);
		x++;
	}
	return (0);
}
