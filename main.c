/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#             */
/*   Updated: 2019/03/08 00:53:07 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_printf(const char *format, ...);
long long	ft_atoi(char const *str);
void		ft_itoa(long long nb, char (*buff)[21]);
void		ft_utoa_base(unsigned long long nb, int base, int maj, char (*buff)[23]);

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *fmt = "Je vais afficher trois lettres : %c, %c, %c\n\
Et voilà une phrase : %s, et une autre : %s, voilà\n\
Maintenant, voilà un chiffre: %#-027.24llo, tada !\n";
	char *str = "une phrase";
	char *str2 = "hello world";
	long long unsigned nb = 0xffffffffffffffff;
	int	ret, ret2;
	ret = printf(fmt, 'A', 'B', 'C', str, str2, nb);
	ret2 = ft_printf(fmt, 'A', 'B', 'C', str, str2, nb);
	printf("%d\n%d\n", ret, ret2);

	// unsigned short nb = 358786455;
	// char buff[23];
	//
	// ft_utoa_base(nb, 10, 0, &buff);
	// printf("%hu\n", nb);
	// printf("%s\n", buff);

	return (0);
}
