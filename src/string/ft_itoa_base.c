/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 22:17:39 by xperrin           #+#    #+#             */
/*   Updated: 2018/03/05 21:56:53 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_cntdigt_b(intmax_t n, size_t radix)
{
	size_t	r;

	r = 1;
	while (n >= (int)radix)
	{
		n /= radix;
		r++;
	}
	return (r);
}

char			*ft_itoa_base(intmax_t n, char *base)
{
	char			*str;
	size_t			radix;
	int				nlen;
	int				isneg;

	isneg = (n < 0) ? 1 : 0;
	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (isneg)
		n = -n;
	radix = ft_strlen(base);
	nlen = (isneg) ? ft_cntdigt_b(n, radix) + 1 : ft_cntdigt_b(n, radix);
	if (!(str = ft_strnew(nlen)))
		return (NULL);
	while (nlen--)
	{
		str[nlen] = base[n % radix];
		n /= radix;
	}
	if (isneg)
		str[0] = '-';
	return (str);
}
