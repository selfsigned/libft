/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprecat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:59:30 by xperrin           #+#    #+#             */
/*   Updated: 2019/08/27 23:08:31 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strprecat(char *dst, const char *src)
{
	size_t l;

	ft_memmove(dst + (l = ft_strlen(src)), dst, ft_strlen(dst) + 1);
	return (ft_memcpy(dst, src, sizeof(char) * l));
}
