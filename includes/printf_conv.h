/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:07:29 by xperrin           #+#    #+#             */
/*   Updated: 2018/03/27 02:47:13 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_CONV_H
# define PRINTF_CONV_H

# include "printf.h"
# include <stdarg.h>

intmax_t	conv_t_int(t_parg parg, va_list ap);
uintmax_t	conv_t_uint(t_parg parg, va_list ap);

size_t		conv_unicode(unsigned char *dst, unsigned int src);
size_t		conv_char(int fd, t_parg parg, va_list ap);
size_t		conv_string(int fd, t_parg parg, va_list ap);
size_t		conv_int(int fd, t_parg parg, va_list ap);
size_t		conv_ptr(int fd, t_parg parg, va_list ap);
size_t		conv_uint(int fd, t_parg parg, va_list ap);

size_t		uint_l_print(int fd, char *str, t_parg parg);
size_t		uint_r_print(int fd, char *str, t_parg parg);
t_parg		zeroflag_handler(t_parg parg, char prepend);

#endif
