/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:56:05 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/14 18:49:30 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_digit(int n)
{
	int i;

	i = 0;
	while (n /= 10)
		i++;
	return (i);
}

char *ft_itoa(int n)
{
	char	*str;
	int		d;
	int		is_neg;

	is_neg = 0;
	if (n < 0)
	{
		n *= -1;
		is_neg = 1;
	}
	d = (is_neg) ? ft_count_digit(n) + 1 : ft_count_digit(n);
	str = (char*)malloc(d);
	str[d] = '\0';
	while (n)
	{
		str[d] = (n % 10 + '0');
		n /= 10;
		d--;
	}
	if (is_neg)
		str[0] = '-';
	return(str);
}
