/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 01:56:57 by xperrin           #+#    #+#             */
/*   Updated: 2018/03/31 16:49:42 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_STRUCTS_H
# define PRINTF_STRUCTS_H

# include "printf.h"

# define WIDTH_CHARS "#0-+ "

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
	int			width;
	int			prec;
	t_length	length;
	char		type;
	size_t		convlen;
	int			error;
}				t_parg;

#endif
