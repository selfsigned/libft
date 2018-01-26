/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:17:20 by xperrin           #+#    #+#             */
/*   Updated: 2018/01/19 20:50:56 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <limits.h>

# define BUFF_SIZE 42

/*
** Ideally sysconf(_SC_OPEN_MAX) but since 42 we'll have to do it the retard way
*/

# ifdef __linux__
#  define OPEN_MAX 10240
# endif

int	get_next_line(const int fd, char **line);

#endif
