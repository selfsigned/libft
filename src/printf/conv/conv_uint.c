/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:38:35 by xperrin           #+#    #+#             */
/*   Updated: 2019/08/27 21:30:57 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

/*
** d = argument ; f = flag ; w = width ; p = precision
**
** Three cases:
**
** Precision only:
** p > w and p > d, basically just zeroes
** (same than left aligned)
**
** Left aligned: (default)
** ' ' | 'prepend' | '0' | itoa(d)
**
** Right aligned:
** 'prepend' | '0' | itoa(d) | ' ': w - p (-prepend?)
*/

size_t		uint_l_print(int fd, char *str, t_parg parg)
{
	int		size;
	size_t	i;
	size_t	w;

	w = ft_strlen(str);
	i = w;
	size = (parg.prec > (int)w) ? parg.prec : (int)w;
	while (parg.width-- - size > 0)
	{
		ft_putchar_fd(' ', fd);
		i++;
	}
	while (size-- - w > 0)
	{
		ft_putchar_fd('0', fd);
		i++;
	}
	(*str) ? ft_putstr_fd(str, fd) : (void)42;
	return (i);
}

size_t		uint_r_print(int fd, char *str, t_parg parg)
{
	int		size;
	size_t	i;
	int		tmp;
	size_t	w;

	w = ft_strlen(str);
	i = w;
	size = (parg.prec > (int)w) ? parg.prec : (int)w;
	tmp = size;
	while (size-- - w > 0)
	{
		ft_putchar_fd('0', fd);
		i++;
	}
	(*str) ? ft_putstr_fd(str, fd) : (void)42;
	while (parg.width-- - tmp > 0)
	{
		ft_putchar_fd(' ', fd);
		i++;
	}
	return (i);
}

size_t		conv_uint(int fd, t_parg parg, va_list ap)
{
	uintmax_t	n;
	char		str[ITOA_B_BUF];

	n = conv_t_uint(parg, ap);
	if (parg.prec == -1 && ft_strchr(parg.flags, '0')
			&& !ft_strchr(parg.flags, '-'))
		parg = (!n && !parg.width && ft_strchr("Oo", parg.type))
			? parg : zeroflag_handler(parg, 0);
	if (!parg.prec && !n && !(ft_strchr(parg.flags, '#')
				&& (parg.type == 'o' || parg.type == 'O')))
		str[0] = '\0';
	else if (parg.type == 'x' || parg.type == 'X')
		(parg.type == 'x') ? ft_utoa_bs(str, n, B_HEX_L)
			: ft_utoa_bs(str, n, B_HEX_U);
	else if (parg.type == 'o' || parg.type == 'O')
	{
		ft_utoa_bs(str, n, B_OCT);
		(ft_strchr(parg.flags, '#') && n) ? ft_strprecat(str,"0") : (char*)0;
	}
	else
		ft_utoa_bs(str, n, B_DEC);
	if (!ft_strchr(parg.flags, '-'))
		return (uint_l_print(fd, str, parg));
	else
		return (uint_r_print(fd, str, parg));
}
