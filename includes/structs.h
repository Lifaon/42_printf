/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#             */
/*   Updated: 2019/02/28 23:55:40 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "defines.h"

typedef struct	s_flag
{
	int			sharp;
	int			zero;
	int			minus;
	int			plus;
	int			space;
}				t_flag;

struct			s_param;

typedef struct	s_func
{
	char		type;
	void		(*f)(struct s_param *);
}				t_func;

typedef struct	s_param
{
	char		*fmt;
	char		buff[BUFF_SIZE + 1];
	int			buff_len;
	int			buff_read;
	va_list		ap;
	t_flag		flag;
	int			width;
	int			preci;
	int			size;
	char		type;
	t_func		func[TYPE_NB];
}				t_param;

#endif
