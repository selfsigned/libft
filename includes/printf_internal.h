/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 01:56:57 by xperrin           #+#    #+#             */
/*   Updated: 2019/08/29 16:02:44 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_INTERNAL_H
# define PRINTF_INTERNAL_H

/*
** printf is a variadic function (look it up on google)
*/
# include <stdarg.h>

/*
** Needed for intmax_t and unicode chars
*/
# include <inttypes.h>
# include <wchar.h>

# define WIDTH_CHARS "#0-+ "
# define CONV_LST "sSpdDioOuUxXcC%b"

# define B_BIN "01"
# define B_OCT "01234567"
# define B_DEC "0123456789"
# define B_HEX_U "0123456789ABCDEF"
# define B_HEX_L "0123456789abcdef"

typedef	enum	e_length
{
	Null,
	hh,
	h,
	l,
	ll,
	j,
	z
}				t_length;

/*
** Printf argument structure for parsing
** ft_printf string format:
** %[flags][width][.precision][length]type
*/

typedef struct	s_parg
{
	char		flags[6];
	char		type;
	size_t		convlen;
	int			width;
	int			prec;
	int			error;
	t_length	length;
}				t_parg;

/*
** Buffer
*/

# define PRINTF_BUF_SIZE 128

typedef struct	s_buf
{
	int			fd;
	size_t		size;
	char		buf[PRINTF_BUF_SIZE];
}				t_buf;

/*
** Types
*/
intmax_t		conv_t_int(t_parg parg, va_list ap);
uintmax_t		conv_t_uint(t_parg parg, va_list ap);

/*
** Handle and print
*/
t_parg			printf_readarg(size_t i, const char *format, va_list ap);
size_t			printf_printarg(int fd, t_parg parg, va_list ap);
size_t			conv_unicode(unsigned char *dst, unsigned int src);
size_t			conv_char(int fd, t_parg parg, va_list ap);
size_t			conv_string(int fd, t_parg parg, va_list ap);
size_t			conv_int(int fd, t_parg parg, va_list ap);
size_t			conv_ptr(int fd, t_parg parg, va_list ap);
size_t			conv_uint(int fd, t_parg parg, va_list ap);
size_t			uint_l_print(int fd, char *str, t_parg parg);
size_t			uint_r_print(int fd, char *str, t_parg parg);
t_parg			zeroflag_handler(t_parg parg, char prepend);

/*
** Bufferize
*/
void			buff_write(int fd, const void *buf, size_t count);
void			buff_putchar(char c, int fd);

#endif
