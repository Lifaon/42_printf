/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#             */
/*   Updated: 2019/03/21 21:41:00 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	print_param(t_param *param)
{
	char	buff[21];
	int		i;

	add_char_to_buff(param, '%');
	if (param->flag.sharp)
		add_char_to_buff(param, '#');
	if (param->flag.plus || param->flag.space)
		add_char_to_buff(param, param->flag.plus ? '+' : ' ');
	if (param->flag.minus || param->flag.zero)
		add_char_to_buff(param, param->flag.minus ? '-' : '0');
	if (param->width > 0)
	{
		i = -1;
		ft_itoa((long long)param->width, &buff);
		while (buff[++i])
			add_char_to_buff(param, buff[i]);
	}
	if (param->preci > -1)
	{
		i = -1;
		add_char_to_buff(param, '.');
		ft_itoa((long long)param->preci, &buff);
		while (buff[++i])
			add_char_to_buff(param, buff[i]);
	}
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

static void	find_width_preci(t_param *param, int *i)
{
	if (param->fmt[*i] >= '1' && param->fmt[*i] <= '9')
		param->width = ft_atoi(param->fmt + *i);
	while (param->fmt[*i] >= '0' && param->fmt[*i] <= '9')
		++(*i);
	if (param->fmt[*i] == '.')
	{
		++(*i);
		param->preci = 0;
		if (param->fmt[*i] >= '0' && param->fmt[*i] <= '9')
			param->preci = ft_atoi(param->fmt + *i);
		while (param->fmt[*i] >= '0' && param->fmt[*i] <= '9')
			++(*i);
	}
}

static void	find_type(t_param *param, int *i)
{
	int j;

	if (param->fmt[*i] == 'h' || param->fmt[*i] == 'l' || param->fmt[*i] == 'L')
	{
		param->size = param->fmt[(*i)++] == 'h' ? SHORT : LONG;
		if ((param->fmt[*i] == 'h' && param->size == SHORT)
		|| (param->fmt[*i] == 'l' && param->size == LONG))
			param->size = param->fmt[(*i)++] == 'h' ? SHORTCHAR : LONGLONG;
	}
	j = -1;
	while (++j < TYPE_NB)
	{
		if (param->fmt[*i] == param->func[j].type)
		{
			param->type = param->fmt[(*i)++];
			param->func[j].f(param);
			return ;
		}
		else if (param->fmt[*i] == '%')
		{
			add_char_to_buff(param, param->fmt[(*i)++]);
			return ;
		}
	}
	print_param(param);
}

void		parse_fmt(t_param *param)
{
	int	i;

	i = 0;
	while (param->fmt[i])
	{
		if (param->fmt[i] != '%')
			add_char_to_buff(param, param->fmt[i++]);
		else
		{
			param->flag.sharp = FALSE;
			param->flag.zero = FALSE;
			param->flag.minus = FALSE;
			param->flag.plus = FALSE;
			param->flag.space = FALSE;
			param->width = 0;
			param->preci = -1;
			param->size = 0;
			++i;
			while (find_flag(param, param->fmt[i]))
				++i;
			find_width_preci(param, &i);
			find_type(param, &i);
		}
	}
	print_buff(param);
}
