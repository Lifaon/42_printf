/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:43:47 by mlantonn          #+#    #+#             */
/*   Updated: 2019/03/21 21:39:49 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv.h"

static void	get_sized_param(t_ull *nb, t_param *param)
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

static void	print_width(int len, char c, int base, t_param *param)
{
	int tmp;

	if (param->flag.sharp && (base == 16 || base == 8))
		tmp = base == 16 ? 2 : 1;
	else
		tmp = 0;
	if (param->preci >= 0 && len < param->preci)
		tmp += param->preci - len;
	if (len + tmp < param->width)
	{
		while (len + tmp < param->width)
		{
			++len;
			add_char_to_buff(param, c);
		}
		if (param->preci >= 0 && c == ' ')
			param->width = 0;
	}
	if (c == '0' && param->preci >= 0)
		while (len < param->preci)
		{
			++len;
			add_char_to_buff(param, c);
		}
}

static void	set_base(int *base, char type)
{
	if (type == 'o')
		*base = 8;
	else if (type == 'u')
		*base = 10;
	else
		*base = 16;
}

static void	add_sharp(t_param *param, int base, char c)
{
	if (param->flag.sharp)
	{
		if (base == 8 && c != '0')
			add_char_to_buff(param, '0');
		else if (base == 16)
		{
			add_char_to_buff(param, '0');
			add_char_to_buff(param, param->type);
		}
	}
}

void		u(t_param *param)
{
	t_ull	nb;
	char	buff[23];
	int		base;
	int		len;
	int		i;

	get_sized_param(&nb, param);
	set_base(&base, param->type);
	ft_utoa_base(nb, base, param->type == 'X', &buff);
	len = 0;
	while (buff[len])
		++len;
	if (len < param->width && !param->flag.minus && (!param->flag.zero
		|| (param->preci >= 0)))
		print_width(len, ' ', base, param);
	add_sharp(param, base, buff[0]);
	if ((len < param->width && !param->flag.minus) || param->preci >= 0)
		print_width(len, '0', base, param);
	i = 0;
	while (buff[i])
		add_char_to_buff(param, buff[i++]);
	if (len < param->width && param->flag.minus)
		print_width(len, ' ', base, param);
}
