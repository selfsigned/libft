/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:35:32 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/11 14:49:01 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	e;

	e = -1;
	i = ft_strlen(dst) - 1;
	while (src[++e] && e < size)
		dst[++i] = src[e];
	dst[++i] = '\0';
	return (e);
}
