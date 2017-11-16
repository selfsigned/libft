/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:30:11 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/16 18:16:03 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	needle_len;
	unsigned int	i;

	i = 0;
	if (!(*needle))
		return ((char*)haystack);
	needle_len = ft_strlen(needle);
	while (*haystack)
	{
		while (haystack[i] == needle[i])
		{
			i++;
			if (i == needle_len)
				return ((char*)haystack);
		}
		i = 0;
		haystack++;
	}
	return (NULL);
}
