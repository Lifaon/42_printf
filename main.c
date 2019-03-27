/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#             */
/*   Updated: 2019/03/27 20:23:11 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <float.h>
#include "ft_printf.h"

void		test_vprintf_functions(int mark, ...)
{
	va_list ap;
	int		fd;
	char	*str1;
	char	*str2;

	va_start(ap, mark);

	// vprintf
	vprintf("Test du vprintf: %d / %d / %d\n", ap);
	va_end(ap);
	va_start(ap, mark);
	ft_vprintf("Test du vprintf: %d / %d / %d\n", ap);
	va_end(ap);
	va_start(ap, mark);

	// vdprintf
	fd = open("./test_vdprintf.txt", O_CREAT | O_WRONLY | O_APPEND);
	if (fd == -1)
	{
		perror("open error! :(");
		return ;
	}
	vdprintf(fd, "Test du vdprintf: %d / %d / %d\n", ap);
	va_end(ap);
	va_start(ap, mark);
	ft_vdprintf(fd, "Test du ft_vdprintf: %d / %d / %d\n", ap);
	va_end(ap);
	va_start(ap, mark);
	close(fd);

	// vsprintf
	str1 = (char *)malloc(4096);
	str2 = (char *)malloc(4096);
	if (str1 == NULL || str2 == NULL)
	{
		perror("malloc error! :(");
		return ;
	}
	vsprintf(str1, "Test du vsprintf: %d / %d / %d\n", ap);
	va_end(ap);
	va_start(ap, mark);
	ft_vsprintf(str2, "Test du ft_vsprintf: %d / %d / %d\n", ap);
	va_end(ap);
	va_start(ap, mark);
	puts(str1);
	puts(str2);

	// vsnprintf
	vsnprintf(str1, 14, "Test du vsnprintf: %d / %d / %d\n", ap);
	va_end(ap);
	va_start(ap, mark);
	ft_vsnprintf(str2, 14, "Test du ft_vsnprintf: %d / %d / %d\n", ap);
	puts(str1);
	puts(str2);
	free(str1);
	free(str2);

	va_end(ap);
}

void		test_printf_functions()
{
	int		fd;
	char	*str1;
	char	*str2;

	// printf
	printf("Test du printf %d\n", 42);
	ft_printf("Test du ft_printf %d\n", 42);

	// dprintf
	fd = open("./test_dprintf.txt", O_CREAT | O_WRONLY | O_APPEND);
	if (fd == -1)
	{
		perror("open error! :(");
		return ;
	}
	dprintf(fd, "Test du dprintf %d\n", 42);
	ft_dprintf(fd, "Test du ft_dprintf %d\n", 42);
	close(fd);

	// sprintf
	str1 = (char *)malloc(4096);
	str2 = (char *)malloc(4096);
	if (str1 == NULL || str2 == NULL)
	{
		perror("malloc error! :(");
		return ;
	}
	sprintf(str1, "Test du sprintf %d\n", 42);
	ft_sprintf(str2, "Test du ft_sprintf %d\n", 42);
	puts(str1);
	puts(str2);

	// snprintf
	snprintf(str1, 14, "Test du snprintf %d\n", 42);
	ft_snprintf(str2, 14, "Test du ft_snprintf %d\n", 42);
	puts(str1);
	puts(str2);
	free(str1);
	free(str2);
}

int			main(void)
{
	ft_printf("[%p]\n\
[%50p]\n\
[%4p]\n\
[%3p]\n\
[%2p]\n\
[%1p]\n\
[%0p]\n\
[%01p]\n\
[%02p]\n\
[%03p]\n\
[%04p]\n\
[%040p]\n\
[%.0p]\n\
[%.p]\n\
[%.1p]\n\
[%.2p]\n\
[%.3p]\n\
[%.4p]\n\
[%.10p]\n\
[%.40p]\n\
[%40.40p]\n\
[%40.38p]\n\
[%38.40p]\n\
[%1.4p]\n\
[%1.1p]\n\
[%2.2p]\n\
[%4.1p]\n\
[%18.0p]\n\
[%1.0p]\n\
[%01.0p]\n\
[%018.0p]\n\
[%010.20p]\n\
[%010.10p]\n\
[%p]\n\
[%10p]\n\
[%1p]\n\
[%2p]\n\
[%4p]\n\
[%40p]\n\
[%01p]\n\
[%02p]\n\
[%04p]\n\
[%010p]\n\
[%10.0p]\n\
[%10.2p]\n\
[%10.4p]\n\
[%10.10p]\n\
[%010.0p]\n\
[%010.2p]\n\
[%010.4p]\n\
[%010.10p]\n\
[%010.20p]\n\
[%+p]\n\
[%+1p]\n\
[%+2p]\n\
[%+3p]\n\
[%+4p]\n\
[%+10p]\n\
[%+20p]\n\
[%+01p]\n\
[%+02p]\n\
[%+03p]\n\
[%+04p]\n\
[%+010p]\n\
[%+020p]\n\
[%+.1p]\n\
[%+.2p]\n\
[%+.3p]\n\
[%+.4p]\n\
[%+.10p]\n\
[%+.20p]\n\
[%+1.1p]\n\
[%+2.2p]\n\
[%+3.3p]\n\
[%+4.4p]\n\
[%+10.10p]\n\
[%+20.20p]\n\
[%+2.1p]\n\
[%+3.2p]\n\
[%+4.3p]\n\
[%+5.4p]\n\
[%+15.10p]\n\
[%+25.20p]\n\
[%+2.3p]\n\
[%+3.4p]\n\
[%+4.5p]\n\
[%+5.6p]\n\
[%+15.18p]\n\
[%+25.28p]\n\
[%+01.1p]\n\
[%+02.2p]\n\
[%+03.3p]\n\
[%+04.4p]\n\
[%+010.10p]\n\
[%+020.20p]\n\
[%+02.1p]\n\
[%+03.2p]\n\
[%+04.3p]\n\
[%+05.4p]\n\
[%+015.10p]\n\
[%+025.20p]\n\
[%+02.3p]\n\
[%+03.4p]\n\
[%+04.5p]\n\
[%+05.6p]\n\
[%+015.18p]\n\
[%+025.28p]\n"
, 0);
	// ft_printf("%.0p\n", 0);
	// ft_printf("%b\n", 0);
	// ft_printf("%b\n", 22708568336987221);
	// ft_printf("%b\n", 0xffffffffffffffff);
	// test_printf_functions();
	// test_vprintf_functions(0, 42, 101, 2019);
	return(0);
}
