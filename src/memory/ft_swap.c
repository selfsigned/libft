/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 04:48:32 by xperrin           #+#    #+#             */
/*   Updated: 2018/05/27 06:25:49 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_swap(void *a, void *b, size_t size)
{
	char	*c;
	char	*d;
	char	tmp;
	size_t	i;

	if (a == b)
		return ;
	c = (char*)a;
	d = (char*)b;
	i = -1;
	while (++i != size)
	{
		tmp = c[i];
		c[i] = d[i];
		d[i] = tmp;
	}
}
