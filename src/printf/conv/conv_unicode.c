/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_unicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 01:11:32 by xperrin           #+#    #+#             */
/*   Updated: 2018/03/31 22:49:05 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static	size_t	utf_twob_range(unsigned char *d, unsigned int n)
{
	d[0] = (n >> 6) + 0xC0;
	d[1] = (n & 0x3F) + 0x80;
	return (2);
}

static	size_t	utf_threeb_range(unsigned char *d, unsigned int n)
{
	d[0] = (n >> 12) + 0xE0;
	d[1] = ((n >> 6) & 0x3F) + 0x80;
	d[2] = (n & 0x3F) + 0x80;
	return (3);
}

static	size_t	utf_fourb_range(unsigned char *d, unsigned int n)
{
	d[0] = (n >> 17) + 0xF0;
	d[1] = ((n >> 12) & 0x3F) + 0x80;
	d[2] = ((n >> 6) & 0x3F) + 0x80;
	d[3] = (n & 0x3F) + 0x80;
	return (4);
}

size_t			conv_unicode(unsigned char *d, unsigned int n)
{
	if (n <= 0x7F || MB_CUR_MAX <= 1)
	{
		d[0] = n;
		return (1);
	}
	else if (n <= 0x7FF || MB_CUR_MAX == 2)
		return (utf_twob_range(d, n));
	else if (n <= 0xFFFF || MB_CUR_MAX == 3)
		return (utf_threeb_range(d, n));
	else if (n <= 0x10FFFF || MB_CUR_MAX == 4)
		return (utf_fourb_range(d, n));
	d[0] = 0xEF;
	d[1] = 0xBF;
	d[2] = 0xBD;
	return (3);
}
