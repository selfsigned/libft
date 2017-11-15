/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:30:29 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/15 14:40:28 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_digit(int n)
{
	int i;

	i = 0;
	while (n /= 10)
		i++;
	return (i);
}

static	char	*magic(int n, int len, int is_neg)
{
	char *dst;

	if (!(dst = (char*)malloc(len)))
		return (NULL);
	dst[len] = '\0';
	while (len != -1)
	{
		dst[len] = (n % 10 + '0');
		n /= 10;
		len--;
	}
	if (is_neg)
		dst[0] = '-';
	return (dst);
}

char			*ft_itoa(int n)
{
	int		d;
	int		is_neg;

	is_neg = 0;
	if (n < 0)
	{
		n *= -1;
		is_neg = 1;
	}
	d = (is_neg) ? count_digit(n) + 1 : count_digit(n);
	return (magic(n, d, is_neg));
}
