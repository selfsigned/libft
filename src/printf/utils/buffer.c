/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 13:02:54 by xperrin           #+#    #+#             */
/*   Updated: 2019/08/29 15:50:37 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "printf_internal.h"

static void	flush_buffer(t_buf *buffer)
{
	if (buffer->size != 0)
		write(buffer->fd, buffer->buf, buffer->size);
	buffer->size = 0;
}

void		buff_putchar(char c, int fd)
{
	buff_write(fd, &c, 1);
}

/*
** fd -> negative fd and 0 count to flush (print)
*/

void		buff_write(int fd, const void *buf, size_t count)
{
	static t_buf	b = {-42, 0, {0}};
	size_t			i;
	char			tmp;

	if (fd != b.fd)
	{
		flush_buffer(&b);
		b.fd = fd;
	}
	i = -1;
	while (++i < count)
	{
		tmp = *((const char*)buf + i);
		b.buf[b.size] = tmp;
		b.size++;
		if (tmp == '\n' || b.size == PRINTF_BUF_SIZE)
			flush_buffer(&b);
	}
}
