/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cntdigit_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 19:39:49 by xperrin           #+#    #+#             */
/*   Updated: 2019/08/24 16:16:44 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cntdigt_b(intmax_t n, size_t radix)
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
