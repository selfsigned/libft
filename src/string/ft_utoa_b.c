/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 22:33:42 by xperrin           #+#    #+#             */
/*   Updated: 2019/08/26 19:57:58 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_utoa_b(uintmax_t n, char *base)
{
	char	buf[66];

	ft_utoa_bs(buf, n, base);
	return (ft_strdup(buf));
}
