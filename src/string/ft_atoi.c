/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:37:42 by xperrin           #+#    #+#             */
/*   Updated: 2018/03/13 23:12:30 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int		r;
	int				neg;

	r = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	neg = (*str == '-') ? 1 : 0;
	str = (*str == '+' || neg) ? str + 1 : str;
	while (ft_isdigit(*str))
		r = r * 10 + (*str++ - '0');
	if (neg)
		return (-r);
	return (r);
}
