/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#             */
/*   Updated: 2019/03/21 21:23:52 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "ft_printf.h"

void		test_vprintf_functions(int mark, ...)
{
	va_list ap;
	int		fd;
	FILE	*stream;
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

	// vfprintf
	stream = fopen("./test_vfprintf.txt", "a");
	if (stream == NULL)
	{
		perror("fopen error! :(");
		return ;
	}
	vfprintf(stream, "Test du vfprintf: %d / %d / %d\n", ap);
	va_end(ap);
	va_start(ap, mark);
	ft_vfprintf(stream, "Test du ft_vfprintf: %d / %d / %d\n", ap);
	va_end(ap);
	va_start(ap, mark);
	fclose(stream);

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
	FILE	*stream;
	char	*str1;
	char	*str2;

	// printf
	printf("Test du printf %d\n", 42);
	ft_printf("Test du printf %d\n", 42);

	// fprintf
	stream = fopen("./test_fprintf.txt", "a");
	if (stream == NULL)
	{
		perror("fopen error! :(");
		return ;
	}
	fprintf(stream, "Test du fprintf %d\n", 42);
	ft_fprintf(stream, "Test du ft_fprintf %d\n", 42);
	fclose(stream);

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

int			main(int ac, char **av)
{
	ft_printf("%b\n", 0);
	ft_printf("%b\n", 22708568336987221);
	ft_printf("%b\n", 0xffffffffffffffff);
	test_printf_functions();
	test_vprintf_functions(0, 42, 101, 2019);
	return(0);
}
