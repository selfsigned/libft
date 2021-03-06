/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 22:17:39 by xperrin           #+#    #+#             */
/*   Updated: 2019/08/27 18:46:13 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_b(intmax_t n, char *base)
{
	char	buf[ITOA_B_BUF];

	ft_itoa_bs(buf, n, base);
	return (ft_strdup(buf));
}
