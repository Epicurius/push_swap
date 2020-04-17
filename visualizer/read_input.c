/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 09:36:44 by nneronin          #+#    #+#             */
/*   Updated: 2020/03/05 18:26:40 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libft/libft.h"
#include "visualizer.h"
#include "./libft/get_next_line.h"

int			find(char *str)
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

int			count(int ac, char **av, int x, int num)
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

int			validity(char *str, t_stack *stc)
{
	long	tmp;
	int		x;

	x = stc->i;
	tmp = ft_atoi(str);
	if (tmp > 2147483647 || tmp < -2147483648)
		return (1);
	while (x <= stc->size_a)
	{
		if (stc->a[x] == (int)tmp)
			return (1);
		x++;
	}
	stc->a[stc->i] = (int)tmp;
	stc->i -= 1;
	return (0);
}

int			get_nbr(int ac, char **av, t_stack *stc)
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
				if (validity(temp[y], stc) == 1)
					return (-1);
				y += 1;
			}
		}
		else if (validity(av[x], stc) == 1)
			return (-1);
		x += 1;
	}
	return (0);
}

int			read_input(int ac, char **av, t_stack *stc)
{
	char		*line;
	int			c;

	line = NULL;
	if ((c = count(ac, av, 1, 0)) == -1)
		return (-1);
	stc->a = (int *)malloc(sizeof(int) * c);
	stc->b = (int *)malloc(sizeof(int) * c);
	stc->i = c - 1;
	stc->size_a = c - 1;
	if ((get_nbr(ac, av, stc)) == -1)
		return (-1);
	while ((get_next_line(0, &line)) > 0)
	{
		if (ft_cmd(stc, line) == -1)
			break ;
		ft_strdel(&line);
	}
	free(line);
	return (0);
}
