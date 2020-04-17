/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:10:51 by nneronin          #+#    #+#             */
/*   Updated: 2020/03/07 15:59:00 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "checker.h"

int		ft_sort(int *a, int size)
{
	int x;

	x = 0;
	while (x < size)
	{
		if (a[x] < a[x + 1] && x != size)
		{
			write(1, "KO\n", 3);
			return (-1);
		}
		x++;
	}
	write(1, "OK\n", 3);
	return (0);
}

void		print(int *a, int *b, t_stack *stc, int ac)
{
	int x;

	x = ac - 1; //fix!
	x = stc->size_a > stc->size_b ? stc->size_a : stc->size_b;
	ft_putstr("A_stack:");
	ft_putnbr(stc->size_a);
	ft_putstr("	B_stack:");
	ft_putnbr(stc->size_b);
	ft_putstr("\n");
	while (x >= 0)
	{
		if (stc->size_a >= x)
			ft_putnbr(a[x]);
		ft_putstr("		");
		if (stc->size_b >= x)
			ft_putnbr(b[x]);
		write(1, "\n", 1);
		x--;
	}
	stc->debug > 2 ? usleep(100000) : 0;
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
	stc->zero = 0;
	stc->moves = 0;
	stc->size_b = -1;
	if (read_input(ac, av, stc) == -1)
		write(1, "Error\n", 6);
	if (stc->debug > 1)
	{
		write(1, "Moves: ", 7);
		ft_putnbr(stc->moves);
	}
	return (0);
}
