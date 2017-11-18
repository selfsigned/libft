/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:19:59 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/18 01:20:08 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*str;

	i = -1;
	if (!(str = ft_strdup((s))))
		return (NULL);
	str = ft_strdup(s);
	while (s[++i])
		*str = f(s[i]);
	str[i] = '\0';
	return (str);
}
