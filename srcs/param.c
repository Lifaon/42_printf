/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#             */
/*   Updated: 2019/03/01 00:01:46 by mlantonn         ###   ########.fr       */
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

static int	find_flag(t_param *param, char c)
{
	if (c == '#')
		param->flag.sharp = TRUE;
	else if (c == '0')
		param->flag.zero = TRUE;
	else if (c == '-')
		param->flag.minus = TRUE;
	else if (c == '+')
		param->flag.plus = TRUE;
	else if (c == ' ')
		param->flag.space = TRUE;
	else
		return (0);
	return (1);
}

static void	print_param(t_param *param)
{
	add_char_to_buff(param, '%');
	if (param->flag.sharp)
		add_char_to_buff(param, '#');
	if (param->flag.plus)
		add_char_to_buff(param, '+');
	else if (param->flag.space)
		add_char_to_buff(param, ' ');
	if (param->flag.minus)
		add_char_to_buff(param, '-');
	else if (param->flag.zero)
		add_char_to_buff(param, '0');
	// print width
	// print precision
}

static void	find_type(t_param *param, int *i)
{
	int j;

	j = -1;
	while (++j < TYPE_NB)
		if (param->fmt[*i] == param->func[j].type)
		{
			++(*i);
			param->func[j].f(param);
			return ;
		}
	print_param(param);
}

void		parse_param(t_param *param, int *i)
{
	reset_param(param);
	++(*i);
	if (param->fmt[*i] == '%')
	{
		add_char_to_buff(param, '%');
		++(*i);
		return ;
	}
	while (find_flag(param, param->fmt[*i]))
		++(*i);
	// find_width(param, i);
	// find_precision(param, i);
	// find_size(param, i);
	find_type(param, i);
}
