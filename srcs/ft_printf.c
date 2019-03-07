/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#             */
/*   Updated: 2019/03/08 00:09:16 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_fmt(t_param *param)
{
	int	i;

	i = 0;
	while(param->fmt[i])
	{
		if (param->fmt[i] != '%')
			add_char_to_buff(param, param->fmt[i++]);
		else
			parse_param(param, &i);
	}
	if (param->buff_len)
		print_buff(param);
}

void	init_func_ptr(t_param *param)
{
	param->func[0].type = 'c';
	param->func[0].f = c;
	param->func[1].type = 's';
	param->func[1].f = s;
	// param->func[2].type = 'p';
	// param->func[2].f = p;
	param->func[2].type = 'd';
	param->func[2].f = i;
	param->func[3].type = 'i';
	param->func[3].f = i;
	param->func[4].type = 'u';
	param->func[4].f = u;
	param->func[5].type = 'o';
	param->func[5].f = o;
	param->func[6].type = 'x';
	param->func[6].f = x;
	param->func[7].type = 'X';
	param->func[7].f = x;
	// param->func[9].type = 'f';
	// param->func[9].f = f;
}

int		ft_printf(const char *fmt, ...)
{
	t_param		param;

	param.fmt = (char *)fmt;
	param.buff_len = 0;
	param.buff_read = 0;
	init_func_ptr(&param);
	va_start(param.ap, fmt);
	parse_fmt(&param);
	va_end(param.ap);
	return (param.buff_read);
}
