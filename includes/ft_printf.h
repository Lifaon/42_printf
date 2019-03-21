/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#             */
/*   Updated: 2019/03/21 18:00:00 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_fprintf(FILE *stream, const char *fmt, ...);
int		ft_dprintf(int fd, const char *fmt, ...);
int		ft_sprintf(char *str, const char *fmt, ...);
int		ft_snprintf(char *str, size_t size, const char *fmt, ...);

int		ft_vprintf(const char *fmt, va_list ap);
int		ft_vfprintf(FILE *stream, const char *fmt, va_list ap);
int		ft_vdprintf(int fd, const char *fmt, va_list ap);
int		ft_vsprintf(char *str, const char *fmt, va_list ap);
int		ft_vsnprintf(char *str, size_t size, const char *fmt, va_list ap);

#endif
