/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readarg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:57:10 by xperrin           #+#    #+#             */
/*   Updated: 2018/07/02 08:11:49 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	size_t		p_flags(const char *fmt, t_parg *parg)
{
	size_t	i;

	i = 0;
	ft_bzero(parg->flags, 6);
	while (fmt[i] && ft_strchr(WIDTH_CHARS, fmt[i]))
	{
		if (i < 5)
			parg->flags[i] = fmt[i];
		i++;
	}
	parg->flags[5] = '\0';
	return (i);
}

static	size_t		p_length(const char *fmt, t_parg *parg)
{
	if ((fmt[0] == 'h' && fmt[1] == 'h')
		|| (fmt[0] == 'l' && fmt[1] == 'l'))
	{
		parg->length = (fmt[0] == 'h') ? hh : ll;
		return (2);
	}
	if (fmt[0] == 'h' || fmt[0] == 'l')
	{
		parg->length = (fmt[0] == 'h') ? h : l;
		return (1);
	}
	if (fmt[0] == 'j' || fmt[0] == 'z')
	{
		parg->length = (fmt[0] == 'j') ? j : z;
		return (1);
	}
	parg->length = Null;
	return (0);
}

static	size_t		p_width_prec(char o, const char *fmt, t_parg *parg,
						va_list ap)
{
	size_t	i;
	int		r;

	i = 0;
	r = -1;
	if (fmt[i] == '*')
		r = va_arg(ap, int);
	else
	{
		while (ft_isdigit(fmt[i]))
			i++;
	}
	if (o == 'w')
		parg->width = (r >= 0) ? r : ft_atoi(fmt);
	else
		parg->prec = (r >= 0) ? r : ft_atoi(fmt);
	return ((fmt[0] == '*') ? 1 : i);
}

/*
** Printf string syntax:
**  %[flags][width][.precision][length]type
*/

t_parg				printf_readarg(size_t i, const char *fmt, va_list ap)
{
	t_parg	parg;

	parg.error = 0;
	parg.convlen = i;
	i += p_flags(fmt + i, &parg);
	parg.width = 0;
	if (ft_isdigit(fmt[i]) || fmt[i] == '*')
		i += p_width_prec('w', fmt + i, &parg, ap);
	parg.prec = -1;
	if (fmt[i] == '.')
		i += p_width_prec('p', fmt + i + 1, &parg, ap) + 1;
	i += p_length(fmt + i, &parg);
	if (ft_isalnum(fmt[i]) || fmt[i] == '%')
		parg.type = fmt[i++];
	else
		parg.error = 1;
	parg.convlen = i;
	return (parg);
}
