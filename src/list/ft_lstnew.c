/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 11:17:13 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/11 18:21:12 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Allocates (with malloc(3)) and returns a “fresh” link. The
** variables content and content_size of the new link are ini-
** tialized by copy of the parameters of the function. If the pa-
** rameter content is nul, the variable content is initialized to
** NULL and the variable content_size is initialized to 0 even
** if the parameter content_size isn’t. The variable next is
** initialized to NULL. If the allocation fails, the function returns
** NULL.
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = ft_memalloc(content_size)))
		{
			free(new);
			return (NULL);
		}
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
