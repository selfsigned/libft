/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:19:59 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/16 19:26:48 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;

	/* if (!(str = ft_memalloc(ft_strlen(s)))) */
	/* 	return (NULL); */
	str = ft_strdup(s);
	while (*str)
	{
		*str = f(*str);
		str++;
	}
	return (str);
}
