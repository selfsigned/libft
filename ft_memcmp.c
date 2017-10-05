/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 21:09:48 by xperrin           #+#    #+#             */
/*   Updated: 2017/10/05 21:18:22 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = -1;
	while (++i < n)
	{
		if (((unsigned char*)s1)[i] > ((unsigned char*)s2)[i])
			return (1);
		if (((unsigned char*)s1)[i] < ((unsigned char*)s2)[i])
			return (-1);
	}
	return (0);
}
