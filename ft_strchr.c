/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:58:54 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/15 19:53:35 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int i;

	i = -1;
	s = (char*)s;
	while (s[++i])
		if (s[i] == c)
			return ((char*)s + i);
	return (NULL);
	/* if (*s == '\0' && c != '\0') */
	/* 	return (NULL); */
	/* return ((s[i] == '\0' && c != '\0') ? NULL : (char*)s + i); */
}
