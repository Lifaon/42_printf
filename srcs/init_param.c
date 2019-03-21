/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#             */
/*   Updated: 2019/03/21 21:35:38 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "parse.h"

static void	init_func_ptr(t_param *param)
{
	param->func[0].type = 'c';
	param->func[0].f = c;
	param->func[1].type = 's';
	param->func[1].f = s;
	param->func[2].type = 'p';
	param->func[2].f = p;
	param->func[3].type = 'd';
	param->func[3].f = i;
	param->func[4].type = 'i';
	param->func[4].f = i;
	param->func[5].type = 'u';
	param->func[5].f = u;
	param->func[6].type = 'o';
	param->func[6].f = o;
	param->func[7].type = 'x';
	param->func[7].f = x;
	param->func[8].type = 'X';
	param->func[8].f = x;
	param->func[9].type = 'f';
	param->func[9].f = f;
	param->func[10].type = 'b';
	param->func[10].f = b;
}

void		init_param(t_param *param, const char *fmt)
{
	param->fmt = (char *)fmt;
	param->str = NULL;
	param->stream = NULL;
	param->fd = 1;
	param->buff_len = 0;
	param->buff_read = 0;
	param->buff_max = 0;
	param->is_maxed = FALSE;
	init_func_ptr(param);
}
