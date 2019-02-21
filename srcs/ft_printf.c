/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#             */
/*   Updated: 2019/02/22 00:01:37 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "printf.h"
#include <stdio.h>

int ft_printf(const char *format, ...)
{
	va_list	ap;
	// char	buff[BUFF_SIZE];

	va_start(ap, format);
	printf("%s\n%s\n", format, va_arg(ap, char *));
	va_end(ap);
	return (0);
}
