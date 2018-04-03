/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:23:40 by xperrin           #+#    #+#             */
/*   Updated: 2018/03/28 20:24:56 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	printf_printarg(int fd, t_parg parg, va_list ap)
{
	if (ft_strchr("Cc%", parg.type))
		return (conv_char(fd, parg, ap));
	else if (parg.type == 's' || parg.type == 'S')
		return (conv_string(fd, parg, ap));
	else if (ft_strchr("idDb", parg.type))
		return (conv_int(fd, parg, ap));
	else if ((ft_strchr("xX", parg.type) && ft_strchr(parg.flags, '#'))
		|| parg.type == 'p')
		return (conv_ptr(fd, parg, ap));
	else if (ft_strchr("uUxXoO", parg.type))
		return (conv_uint(fd, parg, ap));
	return (0);
}
