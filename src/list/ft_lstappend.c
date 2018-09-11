/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:13:55 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/11 18:20:38 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**    _______  __________ __
**   / __/ _ \/ __/ __/ // /
**  / _// , _/ _/_\ \/ _  /
** /_/ /_/|_/___/___/_//_/
**
** Append the link element new at the end of the linked list src.
*/

void	ft_lstappend(t_list **src, t_list *new)
{
	t_list *node;

	node = *src;
	while (node)
	{
		if (node->next)
			node = node->next;
		else
			break ;
	}
	node->next = new;
}
