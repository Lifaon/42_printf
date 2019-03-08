/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 00:04:21 by mlantonn          #+#    #+#             */
/*   Updated: 2019/03/08 00:15:03 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_sized_param(long long *nb, t_param *param)
{
	if (param->size == SHORTCHAR)
		*nb = (t_ull)(unsigned char)va_arg(param->ap, unsigned int);
	else if (param->size == SHORT)
		*nb = (t_ull)(unsigned short)va_arg(param->ap, unsigned int);
	else if (param->size == LONG)
		*nb = (t_ull)va_arg(param->ap, unsigned long);
	else if (param->size == LONGLONG)
		*nb = (t_ull)va_arg(param->ap, t_ull);
	else
		*nb = (t_ull)va_arg(param->ap, unsigned int);
}

static void print_width(int len, char c, t_param *param)
{
	int tmp;

	tmp = param->flag.sharp ? 2 : 0;
	if (param->preci >= 0 && len < param->preci)
		tmp += param->preci - len;
	if (len + tmp < param->width)
	{
		while (len + tmp < param->width)
		{
			++len;
			add_char_to_buff(param, c);
		}
		if (len + tmp == param->width)
			param->width = 0;
	}
}

static void print_preci(int len, t_param *param)
{
	if (param->preci >= 0)
		while (len < param->preci)
		{
			++len;
			add_char_to_buff(param, '0');
		}
}

static void	add_sharp(t_param *param)
{
	if (param->flag.sharp)
	{
		add_char_to_buff(param, '0');
		add_char_to_buff(param, param->type);
	}
}

void		x(t_param *param)
{
	t_ull	nb;
	char	buff[23];
	int		len;
	int		i;

	get_sized_param(&nb, param);
	ft_utoa_base(nb, 16, param->type == 'X', &buff);
	len = 0;
	while (buff[len])
		++len;
	if (len < param->width && !param->flag.minus
		&& (!param->flag.zero || (param->preci >= 0)))
		print_width(len, ' ', param);
	add_sharp(param);
	if (len < param->width && !param->flag.minus && param->flag.zero)
		print_width(len, '0', param);
	print_preci(len, param);
	i = 0;
	while (buff[i])
		add_char_to_buff(param, buff[i++]);
	if (len < param->width && param->flag.minus)
		print_width(len, ' ', param);
}
