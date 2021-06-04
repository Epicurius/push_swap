/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 09:36:44 by nneronin          #+#    #+#             */
/*   Updated: 2021/06/04 15:07:49 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

	i = stc->debug;
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

void	parse_options(t_stack *stc, char **av)
{
	stc->debug = 0;
	if (ft_strequ(av[1], "-v"))
	{
		stc->debug += 1;
		if (ft_strequ(av[2], "-s"))
			stc->debug += 1;
	}
	else if (ft_strequ(av[1], "-s"))
		ft_printf("{CYAN}[INFO]{RESET} -v flag needed for -s to work!\n");
}

int	read_input(int ac, char **av, t_stack *stc)
{
	char	*line;

	line = NULL;
	stc->moves = 0;
	parse_options(stc, av);
	if (!count(ac, av, stc))
		return (0);
	stc->b = malloc(sizeof(int) * stc->size_a);
	stc->size_a -= 1;
	stc->size_b = -1;
	while ((get_next_line(0, &line)) > 0)
	{
		if (ft_cmd(stc->a, stc->b, stc, line) == -1)
		{
			free(line);
			return (0);
		}
		if (stc->debug >= 1)
			print(stc->a, stc->b, stc, 1);
		ft_strdel(&line);
	}
	free(line);
	return (1);
}
