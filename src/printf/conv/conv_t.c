/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:49:57 by xperrin           #+#    #+#             */
/*   Updated: 2018/03/09 23:13:32 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

intmax_t	conv_t_int(t_parg parg, va_list ap)
{
	intmax_t r;

	r = va_arg(ap, intmax_t);
	if (parg.type == 'D')
		r = (long int)r;
	else if (parg.length == hh)
		r = (char)r;
	else if (parg.length == h)
		r = (short int)r;
	else if (parg.length == l)
		r = (long int)r;
	else if (parg.length == ll)
		r = (long long)r;
	else if (parg.length == z)
		r = (size_t)r;
	else if (parg.length == j)
		r = (intmax_t)r;
	else
		r = (int)r;
	return (r);
}

uintmax_t	conv_t_uint(t_parg parg, va_list ap)
{
	uintmax_t r;

	r = va_arg(ap, uintmax_t);
	if (parg.type == 'p' || parg.type == 'U' || parg.type == 'O')
		r = (unsigned long)r;
	else if (parg.length == hh)
		r = (unsigned char)r;
	else if (parg.length == h)
		r = (unsigned short)r;
	else if (parg.length == l)
		r = (unsigned long)r;
	else if (parg.length == ll)
		r = (unsigned long long)r;
	else if (parg.length == z)
		r = (size_t)r;
	else if (parg.length == j)
		r = (uintmax_t)r;
	else
		r = (unsigned int)r;
	return (r);
}
