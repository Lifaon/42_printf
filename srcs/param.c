/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#             */
/*   Updated: 2019/02/24 14:29:03 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	reset_param(t_param *param)
{
	param->flag.sharp = FALSE;
	param->flag.zero = FALSE;
	param->flag.minus = FALSE;
	param->flag.plus = FALSE;
	param->flag.space = FALSE;
	param->width = -1;
	param->preci = -1;
	param->size = 0;
}

void		parse_param(t_param *param, int *i)
{
	++(*i);
	if (param->fmt[*i] == '%')
	{
		add_char_to_buff(param, '%');
		++(*i);
		return ;
	}
	reset_param(param);
}
