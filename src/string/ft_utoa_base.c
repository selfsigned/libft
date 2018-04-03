/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 22:33:42 by xperrin           #+#    #+#             */
/*   Updated: 2018/03/06 15:26:10 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_cntdigt_b(uintmax_t n, size_t radix)
{
	size_t	r;

	r = 1;
	while (n >= radix)
	{
		n /= radix;
		r++;
	}
	return (r);
}

char			*ft_utoa_base(uintmax_t n, char *base)
{
	char			*str;
	size_t			radix;
	int				nlen;

	radix = ft_strlen(base);
	nlen = ft_cntdigt_b(n, radix);
	if (!(str = ft_strnew(nlen)))
		return (NULL);
	while (nlen--)
	{
		str[nlen] = base[n % radix];
		n /= radix;
	}
	return (str);
}
