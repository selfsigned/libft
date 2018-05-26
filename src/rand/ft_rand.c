/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 22:06:25 by xperrin           #+#    #+#             */
/*   Updated: 2018/05/26 22:07:17 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int             ft_rand(size_t bits)
{
        int fd;
        char *buf;
        int res;

        res = 0;
        if (!bits || (fd = open("/dev/urandom", O_RDONLY)) < 0
                || !(buf = malloc(sizeof(char) * bits)))
                return (0);
        read(fd, buf, bits);
        while (bits--)
                res += buf[bits];
        free(buf);
        return (res);
}

