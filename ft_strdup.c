/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 22:01:12 by xperrin           #+#    #+#             */
/*   Updated: 2017/10/05 22:14:19 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *tmp;

	tmp = ft_memalloc(ft_strlen(s1) + 1);
	if (!tmp)
		return (NULL);
	ft_strcpy(tmp, s1);
	return (tmp);
}
