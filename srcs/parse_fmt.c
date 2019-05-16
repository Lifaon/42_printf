/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#             */
/*   Updated: 2019/05/16 23:51:08 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static t_func func[TYPE_NB] = {
	{'c', c}, {'s', s}, {'p', p}, {'d', i}, {'i', i}, {'u', u}, {'o', o},
	{'x', x}, {'X', x}, {'f', f}, {'b', b}
};

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

static void	find_width_preci(t_param *param)
{
	if (*param->fmt >= '1' && *param->fmt <= '9')
		param->width = ft_atoi(param->fmt);
	else if (*param->fmt == '*')
	{
		param->width = va_arg(param->ap, long long);
		param->fmt++;
	}
	while (*param->fmt >= '0' && *param->fmt <= '9')
		param->fmt++;
	if (*param->fmt == '.')
	{
		param->fmt++;
		param->preci = 0;
		if (*param->fmt >= '0' && *param->fmt <= '9')
			param->preci = ft_atoi(param->fmt);
		else if (*param->fmt == '*')
		{
			param->preci = va_arg(param->ap, long long);
			param->fmt++;
		}
		while (*param->fmt >= '0' && *param->fmt <= '9')
			param->fmt++;
	}
}

static void	find_type(t_param *param)
{
	int j;

	if (*param->fmt == 'h' || *param->fmt == 'l' || *param->fmt == 'L')
	{
		param->size = *(param->fmt++) == 'h' ? SHORT : LONG;
		if ((*param->fmt == 'h' && param->size == SHORT)
		|| (*param->fmt == 'l' && param->size == LONG))
			param->size = *(param->fmt++) == 'h' ? SHORTCHAR : LONGLONG;
	}
	j = -1;
	while (++j < TYPE_NB)
	{
		if (*param->fmt == func[j].type)
		{
			param->type = *(param->fmt++);
			func[j].f(param);
			return ;
		}
		else if (*param->fmt == '%')
		{
			add_char_to_buff(param, *(param->fmt++));
			return ;
		}
	}
	print_param(param);
}

void		parse_fmt(t_param *param)
{
	while (*param->fmt)
	{
		if (*param->fmt != '%')
			add_char_to_buff(param, *(param->fmt++));
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
			param->fmt++;
			while (find_flag(param, *param->fmt))
				param->fmt++;
			find_width_preci(param);
			find_type(param);
		}
	}
	print_buff(param);
}
