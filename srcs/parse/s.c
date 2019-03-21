/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:42:37 by mlantonn          #+#    #+#             */
/*   Updated: 2019/03/04 00:56:16 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv.h"

void	s(t_param *param)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	str = va_arg(param->ap, char *);
	while (str[len])
		++len;
	if (param->preci >= 0 && len > param->preci)
		len = param->preci;
	if (len < param->width && !param->flag.minus)
		while (len++ < param->width)
			add_char_to_buff(param, ' ');
	while (str[i] && (param->preci == -1 || i < param->preci))
		add_char_to_buff(param, str[i++]);
	if (len < param->width && param->flag.minus)
		while (len++ < param->width)
			add_char_to_buff(param, ' ');
}
