/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:14:53 by xperrin           #+#    #+#             */
/*   Updated: 2018/01/19 20:33:03 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

int				get_next_line(const int fd, char **line)
{
	static	char	*res[OPEN_MAX];
	char			buf[BUFF_SIZE + 1];
	int				seek;
	char			*tmp;

	if (fd < 0 || BUFF_SIZE <= 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	res[fd] = (!res[fd]) ? ft_strnew(BUFF_SIZE) : res[fd];
	while ((seek = read(fd, buf, BUFF_SIZE)))
	{
		buf[seek] = '\0';
		tmp = res[fd];
		res[fd] = ft_strjoin(res[fd], buf);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (seek < BUFF_SIZE && !ft_strlen(res[fd]))
		return (0);
	*line = ft_strndup(res[fd], ft_strrlen(res[fd], '\n'));
	if (ft_strlen(res[fd]) > ft_strlen(*line))
		ft_strcpy(res[fd], ft_strchr(res[fd], '\n') + 1);
	else
		ft_strclr(res[fd]);
	return (1);
}
