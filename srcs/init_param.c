/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#             */
/*   Updated: 2019/05/16 23:50:00 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "parse.h"

void		init_param(t_param *param, const char *fmt)
{
	param->fmt = (char *)fmt;
	param->str = NULL;
	param->fd = 1;
	param->buff_len = 0;
	param->buff_read = 0;
	param->buff_max = 0;
	param->is_maxed = FALSE;
}
