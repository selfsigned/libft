/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:41:49 by xperrin           #+#    #+#             */
/*   Updated: 2018/07/02 07:17:36 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

int				ft_vdprintf(int fd, const char *format, va_list ap)
{
	size_t	i;
	int		res;
	t_parg	parg;

	(void)ap;
	res = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			parg = printf_readarg(i, format, ap);
			if (!parg.error)
				res += printf_printarg(fd, parg, ap);
			i = parg.convlen;
		}
		else
		{
			write(fd, format + i, 1);
			i++;
			res += 1;
		}
	}
	return (res);
}
