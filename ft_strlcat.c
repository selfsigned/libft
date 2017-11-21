/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:35:32 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/21 15:22:49 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	e;

	e = -1;
	d = ft_strlen(src);
	if (!size)
		return (d);
	if ((i = ft_strlen(dst)) >= size)
		return (d + i);
	while (src[++e] && e < size)
		dst[e + i] = src[e];
	dst[e + i] = '\0';
	return (e + i);
}
