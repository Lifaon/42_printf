/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#             */
/*   Updated: 2019/02/28 17:47:17 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdarg.h>
# include "conv.h"
# include "parse.h"
# include "structs.h"
# include "defines.h"

void	init_param(t_param *param, const char *fmt);
void	parse_fmt(t_param *param);
void	print_buff(t_param *param);
void	add_char_to_buff(t_param *param, char c);

#endif
