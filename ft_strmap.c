/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:19:59 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/26 15:53:54 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*tmp;

	if (!s || !f || !(str = ft_strdup((s))))
		return (NULL);
	tmp = str;
	while (*s)
		*tmp++ = f(*s++);
	return (str);
}
