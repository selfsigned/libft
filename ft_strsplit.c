/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:15:21 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/22 10:33:56 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_words(const char *s, char c)
{
	unsigned int res;

	res = 0;
	while (*s)
	{
		if (*s == c)
			res++;
		s++;
	}
	return (res);
}

static	int	word_len(const char *s, char c)
{
	unsigned int res;

	res = 0;
	while (*s && *s != c)
		res++;
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	int		wi;
	char	**dst;

	dst = ft_memalloc(count_words(s, c));
	wi = -1;
	while (++wi != count_words(s, c))
	{
		dst[wi] = ft_memalloc(word_len(s, c));
		dst[wi] = ft_strsub(s, 0, word_len(s,c));
	}
	return (dst);
}
