/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:42:37 by mlantonn          #+#    #+#             */
/*   Updated: 2019/02/28 19:25:55 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s(t_param *param)
{
	char	*str;
	int		i;

	i = -1;
	str = (char *)va_arg(param->ap, char *);
	while (str[++i])
		add_char_to_buff(param, str[i]);
}
