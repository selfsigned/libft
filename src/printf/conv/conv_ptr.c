/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:38:35 by xperrin           #+#    #+#             */
/*   Updated: 2018/03/31 16:42:11 by xperrin          ###   ########.fr       */
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

static	size_t		l_print(int fd, char *str, t_parg parg)
{
	int		size;
	size_t	i;
	size_t	w;

	w = ft_strlen(str);
	i = w;
	size = (parg.prec > (int)w) ? parg.prec : (int)w;
	while (parg.width-- - (size + 2) > 0)
	{
		ft_putchar_fd(' ', fd);
		i++;
	}
	(parg.type == 'X') ? ft_putstr_fd("0X", fd) : ft_putstr_fd("0x", fd);
	i += 2;
	while (size-- - w > 0)
	{
		ft_putchar_fd('0', fd);
		i++;
	}
	ft_putstr_fd(str, fd);
	return (i);
}

static	size_t		r_print(int fd, char *str, t_parg parg)
{
	int		size;
	size_t	i;
	int		tmp;
	size_t	w;

	(parg.type == 'X') ? ft_putstr_fd("0x", fd) : ft_putstr_fd("0x", fd);
	w = ft_strlen(str);
	i = (parg.prec > (int)w + 2) ? w : w + 2;
	size = (parg.prec > (int)w) ? parg.prec : (int)w;
	tmp = size + 2;
	while (size-- - w > 0)
	{
		ft_putchar_fd('0', fd);
		i++;
	}
	ft_putstr_fd(str, fd);
	while (parg.width-- - tmp > 0)
	{
		ft_putchar_fd(' ', fd);
		i++;
	}
	return (i);
}

/*
** Function for #.0x
** str is freed in uint_*_print
*/

static	size_t		null_hexa_prec(int fd, uintmax_t n, t_parg parg)
{
	char	*str;

	str = (parg.prec || (parg.prec <= 0 && ft_strchr(parg.flags, '0')))
		? ft_strdup("0") : ft_strdup("\0");
	if (!ft_strchr(parg.flags, '-'))
		n = uint_l_print(fd, str, parg);
	else
		n = uint_r_print(fd, str, parg);
	return (n);
}

/*
** "%p", NULL
** MacOS: 0x0
** glibc: (nil)
**
** And it does matter for moulitest, POSIX is dead.
*/

size_t				conv_ptr(int fd, t_parg parg, va_list ap)
{
	uintmax_t	n;
	char		*str;

	n = conv_t_uint(parg, ap);
	if (parg.prec == -1 && ft_strchr(parg.flags, '0')
			&& !ft_strchr(parg.flags, '-'))
	{
		parg.prec = ((parg.type == 'x' || parg.type == 'X') && !n) ? parg.width
			: parg.width - 2;
		parg.width = 0;
	}
	if ((parg.type == 'x' || parg.type == 'X') && !n)
		return (null_hexa_prec(fd, n, parg));
	if (!n && !parg.prec)
		str = ft_strdup("\0");
	else if (parg.type == 'X')
		str = ft_utoa_base(n, B_HEX_U);
	else
		str = ft_utoa_base(n, B_HEX_L);
	if (!ft_strchr(parg.flags, '-'))
		n = l_print(fd, str, parg);
	else
		n = r_print(fd, str, parg);
	free(str);
	return (n);
}
