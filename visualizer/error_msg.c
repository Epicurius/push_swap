/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:27:54 by nneronin          #+#    #+#             */
/*   Updated: 2021/09/15 11:41:12 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	error_msg(const char *restrict format, ...)
{
	t_pf	p;
	char	buff[PF_BUFF_SIZE];

	write(1, "\x1b[31m[ERROR]\x1b[00m", 17);
	if (format)
	{
		write(1, "\t", 1);
		pf_init(&p, 1);
		p.buffer = buff;
		va_start(p.ap, format);
		pf_read_format((char *)format, &p);
		write(p.fd, p.buffer, p.chars);
		va_end(p.ap);
	}
	else
		write(1, "\n", 1);
	exit(1);
}