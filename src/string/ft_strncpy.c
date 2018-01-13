/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 23:15:33 by xperrin           #+#    #+#             */
/*   Updated: 2018/01/13 02:52:58 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t l;

	i = -1;
	l = ft_strlen(src);
	while (++i < len)
		if (i < l)
			dst[i] = src[i];
		else
			dst[i] = '\0';
	return (dst);
}
