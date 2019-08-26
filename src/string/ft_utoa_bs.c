/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_bs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 19:36:59 by xperrin           #+#    #+#             */
/*   Updated: 2019/08/26 19:56:29 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_utoa_bs(char *dst, uintmax_t n, char *base)
{
	size_t			radix;
	int				nlen;

	radix = ft_strlen(base);
	nlen = ft_cntdigt_b(n, radix);
	dst[0] = '\0';
	dst[nlen] = '\0';
	while (nlen--)
	{
		dst[nlen] = base[n % radix];
		n /= radix;
	}
}
