/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:22:38 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/16 18:31:43 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	needle_len;
	unsigned int	i;
	unsigned int	index;
	unsigned int	tmp;

	i = 0;
	index = 0;
	if (!(*needle))
		return ((char*)haystack);
	needle_len = ft_strlen(needle);
	while (*haystack && index < len)
	{
		tmp = index;
		while (haystack[i] == needle[i] && tmp < len)
		{
			i++;
			tmp++;
			if (i == needle_len)
				return ((char*)haystack);
		}
		i = 0;
		haystack++;
		index++;
	}
	return (NULL);
}
