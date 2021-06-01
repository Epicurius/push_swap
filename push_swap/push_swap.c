/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:10:51 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/31 17:11:19 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(int *a, int *b, t_stack *stc, int ac)
{
	int	x;

	x = ac - 1;
	ft_putstr("A_stack:	B_stack:\n");
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
}

int	main(int ac, char **av)
{
	t_stack		*stc;

	if (ac <= 1)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	stc = ft_memalloc(sizeof(t_stack));
	if (!stc)
		return (-1);
	stc->size_b = 0;
	stc->size_a = 0;
	if (read_input(ac, av, stc) == -1)
		write(1, "Error\n", 6);
	return (0);
}
