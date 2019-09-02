/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 19:54:58 by xperrin           #+#    #+#             */
/*   Updated: 2019/09/02 17:37:20 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "printf_internal.h"

static size_t	wstrlen(wchar_t *s)
{
	size_t			l;
	unsigned char	t[4];

	l = 0;
	while (*s)
		l += conv_unicode(t, *s++);
	return (l);
}

static size_t	wstrlen_p(wchar_t *s, int p)
{
	size_t			i;
	size_t			clen;
	unsigned char	t[4];

	i = 0;
	while (*s)
	{
		clen = conv_unicode(t, *s++);
		if (i + clen > (size_t)p)
			return (p - i);
		i += clen;
	}
	return (i);
}

static size_t	putwstrn(wchar_t *s, size_t n, int fd)
{
	size_t			i;
	size_t			clen;
	unsigned char	c[4];

	i = 0;
	if (!s)
	{
		buff_write(fd, "(null)", 6);
		return (n);
	}
	while (*s && i < n)
	{
		clen = conv_unicode(c, *s++);
		if (i + clen <= n)
			buff_write(fd, c, clen);
		else
			break ;
		i += clen;
	}
	return (i);
}

static size_t	conv_ustring(int fd, t_parg parg, va_list ap)
{
	wchar_t	*u;
	size_t	i;
	size_t	d;
	size_t	c;
	int		z_flag;

	i = 0;
	u = va_arg(ap, wchar_t*);
	d = wstrlen((u) ? u : L"(null)");
	c = (parg.prec > 0) ? wstrlen_p(u, parg.prec) : 0;
	parg.prec = (parg.prec < 0 || d < (size_t)parg.prec) ? (int)d : parg.prec;
	z_flag = (ft_strchr(parg.flags, '0')) ? 1 : 0;
	if (ft_strchr(parg.flags, '-'))
		i = putwstrn(u, parg.prec, fd);
	while (parg.width - parg.prec > 0 - (int)c)
	{
		parg.width--;
		buff_putchar((z_flag) ? '0' : ' ', fd);
		i++;
	}
	if (!ft_strchr(parg.flags, '-'))
		i += putwstrn(u, parg.prec, fd);
	return (i);
}

size_t			conv_string(int fd, t_parg parg, va_list ap)
{
	char	*s;
	size_t	i;
	int		z_flag;

	i = 0;
	if (parg.type == 'S' || parg.length == l)
		return (conv_ustring(fd, parg, ap));
	s = va_arg(ap, char*);
	s = (!s) ? "(null)" : s;
	parg.prec = (parg.prec < 0 || ft_strlen(s) < (size_t)parg.prec)
		? (int)ft_strlen(s) : parg.prec;
	z_flag = (ft_strchr(parg.flags, '0')) ? 1 : 0;
	if (ft_strchr(parg.flags, '-'))
		buff_write(fd, s, parg.prec);
	while (parg.width - parg.prec > 0)
	{
		parg.width--;
		buff_putchar((z_flag) ? '0' : ' ', fd);
		i++;
	}
	if (!ft_strchr(parg.flags, '-'))
		buff_write(fd, s, parg.prec);
	return (i + parg.prec);
}
