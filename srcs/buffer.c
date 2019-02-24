/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#             */
/*   Updated: 2019/02/24 14:29:48 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_buff(t_param *param)
{
	param->buff[param->buff_len] = '\0';
	write(1, param->buff, param->buff_len + 1);
	param->buff_len = 0;
}

void	add_char_to_buff(t_param *param, char c)
{
	param->buff[param->buff_len++] = c;
	if (param->buff_len == BUFF_SIZE)
		print_buff(param);
}
