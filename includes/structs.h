/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#             */
/*   Updated: 2019/03/06 23:43:12 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "defines.h"

typedef unsigned long long	t_ull;

typedef struct		s_flag
{
	int				sharp;
	int				zero;
	int				minus;
	int				plus;
	int				space;
}					t_flag;

struct				s_param;

typedef struct		s_func
{
	char			type;
	void			(*f)(struct s_param *);
}					t_func;

typedef struct		s_param
{
	char			*fmt;
	char			buff[BUFF_SIZE + 1];
	long long		buff_len;
	long long		buff_read;
	va_list			ap;
	t_flag			flag;
	long long		width;
	long long		preci;
	int				size;
	char			type;
	t_func			func[TYPE_NB];
}					t_param;

#endif
