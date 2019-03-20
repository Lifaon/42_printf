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

#include "ft_printf.h"
#include <stdio.h>

static void	test(void)
{
	int		ret[2];
	char	*str = "astek";

	printf("##### Tests simple : 1 point par test reussi #####\n");
	printf(   "0)  Modulo [%%] : {%%}\n");
	ft_printf("=>  Modulo [%%] : {%%}\n");
	printf(   "1) Nombre signe [d] : {%d}\n", 42);
	ft_printf("=>  Nombre signe [d] : {%d}\n", 42);
	printf(   "2) Nombre signe [i] : {%i}\n", 42);
	ft_printf("=>  Nombre signe [i] : {%i}\n", 42);
	printf(   "3) Nombre octal [o] : {%o}\n", 012345);
	ft_printf("=>  Nombre octal [o] : {%o}\n", 012345);
	printf(   "4) Nombre non signe [u] : {%u}\n", 42);
	ft_printf("=>  Nombre non signe [u] : {%u}\n", 42);
	printf(   "5) Nombre hexadecimal [x] : {%x}\n", 0x12345);
	ft_printf("=>  Nombre hexadecimal [x] : {%x}\n", 0x12345);
	printf(   "6) Nombre hexadecimal [X] : {%X}\n", 0x12345);
	ft_printf("=>  Nombre hexadecimal [X] : {%X}\n", 0x12345);
	printf(   "7) Caractere [c] : {%c}\n", 42);
	ft_printf("=>  Caractere [c] : {%c}\n", 42);
	printf(   "8) Chaine [s] : {%s}\n", str);
	ft_printf("=>  Chaine [s] : {%s}\n", str);
	printf(   "9) Pointeur [p] : {%p}\n", str);
	ft_printf("=>  Pointeur [p] : {%p}\n", str);
	printf(   "10) Mauvais parametre [k] : {%k}\n", 42);
	ft_printf("=>   Mauvais parametre [k] : {%k}\n", 42);

	printf("Appuyez sur [entree] pour continuer...\n");
	getchar();

	printf("\n##### Tests pour verifier : -1pt par resultat errone #####\n");
	printf(   "1)  Affichage multiple [d d d] : {%d} {%d} {%d}\n", 0, 42, 2147483647);
	ft_printf("=>  Affichage multiple [d d d] : {%d} {%d} {%d}\n", 0, 42, 2147483647);
	printf(   "2) Affichage multiple [d d d] : {%d} {%d} {%d}\n", -0, -42, -2147483648);
	ft_printf("=>  Affichage multiple [d d d] : {%d} {%d} {%d}\n", -0, -42, -2147483648);
	printf(   "3) Affichage multiple [c d s] : {%c} {%d} {%s}\n", 42, 42, str);
	ft_printf("=>  Affichage multiple [c d s] : {%c} {%d} {%s}\n", 42, 42, str);
	printf(   "4) Affichage multiple [X p d] : {%X} {%p} {%d}\n", 0x12345, str, 42);
	ft_printf("=>  Affichage multiple [X p d] : {%X} {%p} {%d}\n", 0x12345, str, 42);
	printf(   "5) Affichage long [d d d ...] : %d %d %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC);
	ft_printf("=>  Affichage long [d d d ...] : %d %d %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC);

	printf("Appuyez sur une touche pour continuer...\n");
	getchar();

	printf("\n##### Formatage : 1pt pour 3 tests reussis  #####\n");
	printf(   "1) Formatage simple [#d] : {%#d}\n", 42);
	ft_printf("=>  Formatage simple [#d] : {%#d}\n", 42);
	printf(   "2) Formatage simple [#x] : {%#x}\n", 0x12345);
	ft_printf("=>  Formatage simple [#x] : {%#x}\n", 0x12345);
	printf(   "3) Formatage simple [#o] : {%#o}\n", 012345);
	ft_printf("=>  Formatage simple [#o] : {%#o}\n", 012345);
	printf(   "4) Formatage simple [0d] : {%0d}\n", 42);
	ft_printf("=>  Formatage simple [0d] : {%0d}\n", 42);
	printf(   "5) Formatage simple [5d] : {%5d}\n", 42);
	ft_printf("=>  Formatage simple [5d] : {%5d}\n", 42);
	printf(   "6) Formatage simple [ d] : {% d}\n", 42);
	ft_printf("=>  Formatage simple [ d] : {% d}\n", 42);
	printf(   "7) Formatage simple [-d] : {%-d}\n", 42);
	ft_printf("=>  Formatage simple [-d] : {%-d}\n", 42);
	printf(   "8) Formatage simple [+d] : {%+d}\n", 42);
	ft_printf("=>  Formatage simple [+d] : {%+d}\n", 42);
	printf(   "9) Formatage simple [+d] : {%+d}\n", -42);
	ft_printf("=>  Formatage simple [+d] : {%+d}\n", -42);
	printf(   "10) Formatage multiple [ 5d] : {% 5d}\n", 42);
	ft_printf("=>   Formatage multiple [ 5d] : {% 5d}\n", 42);
	printf(   "11) Formatage multiple [-32o] : {%-32o}\n", 012345);
	ft_printf("=>   Formatage multiple [-32o] : {%-32o}\n", 012345);
	printf(   "12) Formatage multiple [-10+d] : {%+-10d}\n", 12345);
	ft_printf("=>   Formatage multiple [-10+d] : {%+-10d}\n", 12345);
	printf(   "13) Formatage ultracompose [-6.3x] : {%-6.3x}\n", 0x12345);
	ft_printf("=>   Formatage ultracompose [-6.3x] : {%-6.3x}\n", 0x12345);
	printf(   "14) Formatage ultracompose [#-6.3d] : {%#-6.3d}\n", -2147483648);
	ft_printf("=>   Formatage ultracompose [#-6.3d] : {%#-6.3d}\n", -2147483648);
	printf(   "15) Formatage long [p x lx] : {%p} {%x} {%lx}\n", 0x42424242, 0x42424242, 0x42424242);
	ft_printf("=>   Formatage long [p x lx] : {%p} {%x} {%lx}\n", 0x42424242, 0x42424242, 0x42424242);
	printf(   "16) Formatage pourcent [30%%] : {%30%}\n");
	ft_printf("=>   Formatage pourcent [30%%] : {%30%}\n");
	printf(   "17) Formatage pourcent [-30pourcent] : {%-30%}\n");
	ft_printf("=>   Formatage pourcent [-30pourcent] : {%-30%}\n");
	ret[0] = printf(   "18) Test de la valeur de retour [-10+d s] : {%+-10d} {%s}\n", 12345, str);
	ret[1] = ft_printf("=>   Test de la valeur de retour [-10+d s] : {%+-10d} {%s}\n", 12345, str);
	printf(   "19) Verification de la valeur de retour [d] : {%d}\n", ret[0]);
	ft_printf("=>   Verification de la valeur de retour [d] : {%d}\n", ret[1]);
	printf(   "20) Test de pile [c c] : {%c} {%c}\n", 0x4142434444434241);
	ft_printf("=>   Test de pile [c c] : {%c} {%c}\n", 0x4142434444434241);
}

int		ft_utoa(unsigned long long nb, char (*buff)[20])
{
	unsigned long long tmp;
	int		ret;
	int		len;

	len = 1;
	tmp = nb;
	while (tmp >= 10)
	{
		tmp /= 10;
		++len;
	}
	ret = len;
	while (len-- > 0)
	{
		(*buff)[len] = '0' + nb % 10;
		nb /= 10;
	}
	(*buff)[ret] = '\0';
	return ret;
}

long double ft_10pow(int n)
{
	long double nb;

	nb = 1.0L;
	if (n == 0)
		return (1.0L);
	if (n > 0)
		while (n-- > 0)
			nb *= 10.0L;
	else
		while (n++ < 0)
			nb /= 10.0L;
	return (nb);
}

void		add_mantissa(char (*str)[4096], long double nb, int precision, int len)
{
	unsigned long long tmp;
	char	buff[20];
	int		scale;
	int		i;
	int		j;

	i = 0;
	scale = 19;
	while (i < precision) {
		if (i + scale >= precision) {
			scale = precision - i;
			nb += 0.5L * ft_10pow(-scale);
		}
		tmp = (unsigned long long)(nb * ft_10pow(scale));
		j = ft_utoa(tmp, &buff);
		while (j++ < scale)
			(*str)[len + i++] = '0';
		j = 0;
		while (buff[j])
			(*str)[len + i++] = buff[j++];
		j = 0;
		while (j++ < scale) {
			nb *= 10.0L;
			nb -= (long double)(char)nb;
		}
	}
}

int			main(int ac, char **av)
{
	float				nb = 0.00000000499;
	char				str1[4096], str2[4096];
	int					cmp;
	int					i, j, k;
	int					precision = 19, length = 9;

	sprintf(str1, "%.*f\n", length, nb);
	sprintf(str2, "0.");
	add_mantissa(&str2, nb, length, 2);
	i = 2;
	cmp = -1;
	while (str1[i] && str2[i]) {
		if (str1[i] != str2[i]) {
			cmp = i - 2;
			break ;
		}
		++i;
	}
	printf("%s%s\n%d\n%.*s\n", str1, str2, cmp, cmp + 2, str2);
	// char	cmd[] = "-g";
	// int		ret[2];
	// int		i = 0;
	//
	// if (ac > 1)
	// {
	// 	while (av[1][i] && av[1][i] == cmd[i])
	// 		++i;
	// 	if (av[1][i] == cmd[i])
	// 		test();
	// }
	// else
	// {
	// 	ret[0] = printf(   "%-020p\n", &i);
	// 	ret[1] = ft_printf("%-020p\n", &i);
	// 	printf("%d / %d\n", ret[0], ret[1]);
	// }
	return(0);
}
