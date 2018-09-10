/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 23:27:15 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/11 01:19:08 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**    _______  __________ __
**   / __/ _ \/ __/ __/ // /
**  / _// , _/ _/_\ \/ _  /
** /_/ /_/|_/___/___/_//_/
**
** Allocates (with malloc(3)) and returns a “fresh” link. The
** variables content and content_size of the new link are ini-
** tialized with the pointer's address.
** If the pointer is nul the variable content_size is ini-
** tialized to 0.
** The variable next is initialized to NULL.
** If the allocation fails, the function returns NULL.
*/

t_list	*ft_lstnewl(void **ptr)
{
	t_list	*new;

	if (!(new = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!*ptr)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = *ptr;
		new->content_size = sizeof(void*);
	}
	new->next = NULL;
	return (new);
}
