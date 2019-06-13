/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_static.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:42:13 by mlantonn          #+#    #+#             */
/*   Updated: 2019/06/13 09:53:39 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_printf.h"

static t_param	param;

static void __attribute__((constructor)) first_init (void)
{
	init_param(&param, NULL);
}

static void __attribute__((destructor)) dump_buffer (void)
{
	print_buff(&param);
}

int			ft_printf_static(const char *fmt, ...)
{
	if (fmt == NULL)
		return (-1);
	param.fmt = (char *)fmt;
	va_start(param.ap, fmt);
	parse_fmt(&param);
	va_end(param.ap);
	return (param.buff_read);
}
