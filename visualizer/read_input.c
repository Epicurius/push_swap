/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:19:15 by nneronin          #+#    #+#             */
/*   Updated: 2021/09/15 11:41:12 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int	find(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		x++;
		if (str[x] == ' ')
			return (1);
	}
	return (0);
}

int	validity(char *str, t_stack *stc)
{
	int		i;
	long	nb;
	int		tmp;

	i = -1;
	nb = ft_latoi(str);
	if (nb > 2147483647 || nb < -2147483648)
		return (1);
	while (++i < stc->size_a)
	{
		if (stc->a[i] == (int)nb)
			return (1);
	}
	if (nb > stc->w)
		stc->w = nb;
	stc->size_a += 1;
	stc->a = ft_realloc(stc->a, sizeof(int) * stc->size_a);
	i = -1;
	while (++i < stc->size_a)
	{
		tmp = stc->a[i];
		stc->a[i] = nb;
		nb = tmp;
	}
	return (0);
}

int	count(int ac, char **av, t_stack *stc)
{
	int		i;
	int		x;
	int		nb;
	char	**arr;

	i = 0;
	while (++i < ac)
	{
		if (!ft_isnum(av[i]))
			return (0);
		if (find(av[i]))
		{
			arr = ft_strsplit(av[i], ' ', &nb);
			x = -1;
			while (++x < nb)
			{
				if (validity(arr[x], stc))
					return (0);
			}
			free(arr);
		}
		else if (validity(av[i], stc))
			return (0);
	}
	return (1);
}

int	ft_cmd(t_stack *stc, char *line)
{
	int		x;
	char	**temp;

	x = -1;
	temp = ft_strsplit("sa sb ss pa pb ra rb rr rra rrb rrr", ' ', NULL);
	while (++x <= 10)
	{
		if (ft_strequ(temp[x], line))
		{
			stc->moves += 1;
			stc->cmd = ft_realloc(stc->cmd, sizeof(int) * stc->moves);
			stc->cmd[stc->moves - 1] = x;
			free(temp);
			return (x);
		}
	}
	free(temp);
	return (-1);
}

int	read_input(int ac, char **av, t_stack *stc)
{
	char	*line;

	line = NULL;
	stc->moves = 0;
	if (!count(ac, av, stc))
		return (0);
	if (stc->size_a > 710)
		error_msg("Stack to large!");
	stc->b = malloc(sizeof(int) * stc->size_a);
	stc->size_a -= 1;
	stc->size_b = -1;
	while ((get_next_line(0, &line)) > 0)
	{
		if (ft_cmd(stc, line) == -1)
			error_msg("ft_cmd.");
		ft_strdel(&line);
	}
	free(line);
	return (1);
}
