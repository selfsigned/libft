/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 03:58:34 by xperrin           #+#    #+#             */
/*   Updated: 2018/05/27 06:24:29 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bubblesort(void *base, size_t nemmb, size_t size,
					int (*cmp)(const void *, const void *))
{
	size_t	i;
	size_t	j;

	i = 0;
	while (++i < nemmb)
	{
		j = -1;
		while (++j < nemmb - 1)
			if (cmp((char*)base + size * j, (char*)base + size * (j + 1)) > 0)
				ft_swap((char*)base + size * j,
					(char*)base + size * (j + 1), size);
	}
}
