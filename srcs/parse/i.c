/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:43:50 by mlantonn          #+#    #+#             */
/*   Updated: 2019/03/06 01:20:43 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_sized_param(long long *nb, t_param *param)
{
	if (param->size == SHORTCHAR)
		*nb = (long long)(char)va_arg(param->ap, int);
	else if (param->size == SHORT)
		*nb = (long long)(short)va_arg(param->ap, int);
	else if (param->size == LONG)
		*nb = (long long)va_arg(param->ap, long);
	else if (param->size == LONGLONG)
		*nb = (long long)va_arg(param->ap, long long);
	else
		*nb = (long long)va_arg(param->ap, int);
}

static void print_width(int *len, char c, t_param *param)
{
	while ((*len)++ < param->width)
		add_char_to_buff(param, c);
}

void	i(t_param *param)
{
	long long	nb;
	int			len;
	int			i;
	char		buff[21];

	get_sized_param(&nb, param);
	ft_itoa(nb, &buff);
	len = 0;
	while (buff[len])
		++len;
	if (nb >= 0 && (param->flag.plus || param->flag.space))
		++len;
	if (len < param->width && !param->flag.minus && !param->flag.zero)
		print_width(&len, ' ', param);
	if (nb >= 0 && (param->flag.plus || param->flag.space))
		add_char_to_buff(param, param->flag.plus ? '+' : ' ');
	if (nb < 0)
		add_char_to_buff(param, '-');
	if (len < param->width && !param->flag.minus)
		print_width(&len, '0', param);
	i = 0;
	while (buff[++i])
		add_char_to_buff(param, buff[i]);
	if (len < param->width && param->flag.minus)
		print_width(&len, ' ', param);
}
