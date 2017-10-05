/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 01:16:43 by xperrin           #+#    #+#             */
/*   Updated: 2017/10/05 19:03:23 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t i;

	i = -1;
	while (++i < len)
	{
		((char*)dst)[i] = ((char*)src)[i];
		if (((char *)src)[i] == c)
			return (++dst + i);
	}
	return (NULL);
}
