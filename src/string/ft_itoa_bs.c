/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 19:39:49 by xperrin           #+#    #+#             */
/*   Updated: 2019/08/26 19:57:18 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** dst  -> Should ideally be 65, to hold every possible number if base is "01"
** n    -> number to convert
** base -> base string, e.g "013456789ABCDEF"
*/

void		ft_itoa_bs(char *dst, intmax_t n, char *base)
{
	size_t			radix;
	int				nlen;
	int				isneg;

	isneg = (n < 0) ? 1 : 0;
	if (n == LONG_MIN)
	{
		ft_strcpy(dst, "-9223372036854775808");
		return ;
	}
	if (isneg)
		n = -n;
	radix = ft_strlen(base);
	nlen = (isneg) ? ft_cntdigt_b(n, radix) + 1 : ft_cntdigt_b(n, radix);
	dst[0] = '\0';
	dst[nlen] = '\0';
	while (nlen--)
	{
		dst[nlen] = base[n % radix];
		n /= radix;
	}
	if (isneg)
		dst[0] = '-';
}
