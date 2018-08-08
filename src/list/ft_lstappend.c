/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:13:55 by xperrin           #+#    #+#             */
/*   Updated: 2018/08/08 19:52:14 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstappend(t_list **src, t_list *new)
{
	t_list *node;

	node = *src;
	while (node)
	{
		if (node->next)
			node = node->next;
		else
			break;
	}
	node->next = new;
}
