/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 22:33:42 by xperrin           #+#    #+#             */
/*   Updated: 2019/08/27 18:47:49 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_utoa_b(uintmax_t n, char *base)
{
	char	buf[ITOA_B_BUF];

	ft_utoa_bs(buf, n, base);
	return (ft_strdup(buf));
}
