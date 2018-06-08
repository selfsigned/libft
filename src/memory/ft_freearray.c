/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 23:14:43 by xperrin           #+#    #+#             */
/*   Updated: 2018/06/10 02:29:52 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_freearray(void **array, size_t nmemb)
{
	size_t	i;

	i = -1;
	while (++i < nmemb)
		free(array[i]);
	free(array);
	array = NULL;
}
