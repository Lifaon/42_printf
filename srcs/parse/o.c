/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 00:04:21 by mlantonn          #+#    #+#             */
/*   Updated: 2019/03/08 00:52:35 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv.h"

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

static void print_width(int len, char c, int sharp, t_param *param)
{
	if (param->preci >= 0 && len < param->preci + sharp)
		sharp = param->preci - len;
	if (len + sharp < param->width)
	{
		while (len + sharp < param->width)
		{
			++len;
			add_char_to_buff(param, c);
		}
		if (param->preci >= 0 && c == ' ')
			param->width = 0;
	}
}

static void print_preci(int len, int sharp, t_param *param)
{
	if (param->preci >= 0)
		while (len + sharp < param->preci)
		{
			++len;
			add_char_to_buff(param, '0');
		}
}

static void	add_sharp(t_param *param, char c)
{
	if (param->flag.sharp && c != '0')
		add_char_to_buff(param, '0');
}

void		o(t_param *param)
{
	t_ull	nb;
	char	buff[23];
	int		len;
	int		i;
	int		sharp;

	get_sized_param(&nb, param);
	ft_utoa_base(nb, 8, param->type == 'X', &buff);
	len = 0;
	sharp = param->flag.sharp && buff[0] != '0' ? 1 : 0;
	while (buff[len])
		++len;
	if (len + sharp < param->width && !param->flag.minus
		&& (!param->flag.zero || (param->preci >= 0)))
		print_width(len, ' ', sharp, param);
	add_sharp(param, buff[0]);
	if (len + sharp < param->width && !param->flag.minus && param->flag.zero)
		print_width(len, '0', sharp, param);
	print_preci(len, sharp, param);
	i = 0;
	while (buff[i])
		add_char_to_buff(param, buff[i++]);
	if (len + sharp < param->width && param->flag.minus)
		print_width(len, ' ', sharp, param);
}
