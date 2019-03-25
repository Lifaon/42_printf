/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#             */
/*   Updated: 2019/03/25 11:16:44 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "structs.h"

void	print_buff(t_param *param)
{
	if (param->str != NULL)
	{
		param->str[param->buff_read] = '\0';
		return ;
	}
	if (!param->buff_len)
		return ;
	write(param->fd, param->buff, param->buff_len);
	param->buff_read += param->buff_len;
	param->buff_len = 0;
}

void	add_char_to_buff(t_param *param, char c)
{
	if (param->str != NULL)
	{
		if (!param->is_maxed || param->buff_read + 1 < param->buff_max)
			param->str[param->buff_read++] = c;
	}
	else
	{
		param->buff[param->buff_len++] = c;
		if (param->buff_len == BUFF_SIZE)
			print_buff(param);
	}
}
