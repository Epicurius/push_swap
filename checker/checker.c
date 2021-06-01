/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:10:51 by nneronin          #+#    #+#             */
/*   Updated: 2021/06/01 16:48:02 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_sorted(int *a, int size)
{
	int	x;

	x = 0;
	while (x < size)
	{
		if (a[x] < a[x + 1])
			return (0);
		x++;
	}
	return (1);
}

void	print(int *a, int *b, t_stack *stc, int ac)
{
	int	x;

	x = ft_max(stc->size_a, stc->size_b);
	ft_printf("A_stack:%d\t\tB_Stack:%d\n", stc->size_a, stc->size_b);
	while (x >= 0)
	{
		if (stc->size_a >= x)
			ft_putnbr(a[x]);
		ft_putstr("\t\t\t");
		if (stc->size_b >= x)
			ft_putnbr(b[x]);
		write(1, "\n", 1);
		x--;
	}
	write(1, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", 34);
	if (stc->debug == 2)
		usleep(100000);
}

int	main(int ac, char **av)
{
	t_stack	*stc;

	if (ac <= 1)
		ft_printf("{RED}[ERROR]{RESET}\n");
	stc = ft_memalloc(sizeof(t_stack));
	if (!read_input(ac, av, stc))
		ft_printf("{RED}[ERROR]{RESET}\n");
	else
	{
		if (is_sorted(stc->a, stc->size_a))
			ft_printf("{GREEN}[OK]{RESET} Moves:%d\n", stc->moves);
		else
			ft_printf("{ORANGE}[KO]{RESET}\n");
	}
	if (stc->a)
		free(stc->a);
	if (stc->b)
		free(stc->b);
	free(stc);
	return (0);
}
