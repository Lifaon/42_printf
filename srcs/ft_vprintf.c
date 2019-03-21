/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#             */
/*   Updated: 2019/03/21 21:35:33 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		ft_vprintf(const char *fmt, va_list ap)
{
	t_param	param;

	init_param(&param, fmt);
	va_copy(param.ap, ap);
	parse_fmt(&param);
	return (param.buff_read);
}

int		ft_vfprintf(FILE *stream, const char *fmt, va_list ap)
{
	t_param	param;

	init_param(&param, fmt);
	param.stream = stream;
	va_copy(param.ap, ap);
	parse_fmt(&param);
	return (param.buff_read);
}

int		ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	t_param	param;

	init_param(&param, fmt);
	param.fd = fd;
	va_copy(param.ap, ap);
	parse_fmt(&param);
	return (param.buff_read);
}

int		ft_vsprintf(char *str, const char *fmt, va_list ap)
{
	t_param	param;

	init_param(&param, fmt);
	param.str = str;
	va_copy(param.ap, ap);
	parse_fmt(&param);
	return (param.buff_read);
}

int		ft_vsnprintf(char *str, size_t size, const char *fmt, va_list ap)
{
	t_param	param;

	init_param(&param, fmt);
	param.str = str;
	param.buff_max = size;
	param.is_maxed = TRUE;
	va_copy(param.ap, ap);
	parse_fmt(&param);
	return (param.buff_read);
}
