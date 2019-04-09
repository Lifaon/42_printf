/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#             */
/*   Updated: 2019/04/09 19:53:27 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdarg.h>
# include <stdlib.h>
# include "defines.h"

typedef unsigned long long	t_ull;

typedef struct	s_flag
{
	int			sharp;
	int			zero;
	int			minus;
	int			plus;
	int			space;
}				t_flag;

struct s_param;

typedef struct	s_func
{
	char		type;
	void		(*f)(struct s_param *);
}				t_func;

typedef struct	s_param
{
	char		*fmt;
	char		*str;
	int			fd;
	char		buff[BUFF_SIZE + 1];
	t_ull		buff_len;
	t_ull		buff_read;
	size_t		buff_max;
	int			is_maxed;
	va_list		ap;
	t_flag		flag;
	long long	width;
	long long	preci;
	int			size;
	char		type;
	t_func		func[TYPE_NB];
}				t_param;

#endif
