/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 22:45:08 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/26 15:54:25 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	char			*tmp;

	if (!s || !f || !(str = ft_strdup((s))))
		return (NULL);
	i = 0;
	tmp = str;
	while (*s)
		*tmp++ = f(i++, *s++);
	return (str);
}
