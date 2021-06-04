/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 09:36:44 by nneronin          #+#    #+#             */
/*   Updated: 2021/06/04 15:52:38 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] == 45 && !(str[x + 1] > 48 && str[x + 1] <= 57))
			return (0);
		if ((str[x] < 48 || str[x] > 57) && str[x] != 32 && str[x] != 45)
			return (0);
		if ((str[x] > 48 && str[x] < 57) && str[x + 1] == 45)
			return (0);
		x++;
	}
	return (1);
}

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
		return (0);
	while (++i < stc->size_a)
	{
		if (stc->a[i] == (int)nb)
			return (0);
	}
	stc->size_a += 1;
	stc->a = ft_realloc(stc->a, sizeof(int) * stc->size_a);
	i = -1;
	while (++i < stc->size_a)
	{
		tmp = stc->a[i];
		stc->a[i] = nb;
		nb = tmp;
	}
	return (1);
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
				if (!validity(arr[x], stc))
					break ;
			free(arr);
			if (x < nb)
				return (0);
		}
		else if (!validity(av[i], stc))
			return (0);
	}
	return (1);
}

int	read_input(int ac, char **av, t_stack *stc)
{
	if (!count(ac, av, stc))
		return (-1);
	stc->b = malloc(sizeof(int) * stc->size_a);
	stc->s = -1;
	stc->size_a -= 1;
	stc->size_b = -1;
	if (is_sorted(stc->a, stc->size_a))
		return (0);
	if (stc->size_a <= 10)
		sort_short(stc->a, stc->b, stc, 0);
	else
	{
		while (!is_sorted(stc->a, stc->size_a))
		{
			sort_algo(stc->a, stc->b, stc);
			if (stc->size_a == -1)
				stc->s = stc->size_a;
			else
				stc->s = find_min_max(stc->a, stc->size_a, 's');
		}
	}
	return (0);
}
