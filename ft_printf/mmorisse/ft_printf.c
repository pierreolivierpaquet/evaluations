/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorisse <mmorisse@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:21:51 by mmorisse          #+#    #+#             */
/*   Updated: 2023/11/30 14:23:42 by mmorisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_param(va_list var, const char param)
{
	if (param == 'c')
		return (ft_putchar_fd((va_arg(var, int)), 1));
	else if (param == 's')
		return ((ft_putstr_fd(va_arg(var, char *), 1)));
	else if (param == 'd' || param == 'i')
		return (ft_putnbr(va_arg(var, int)));
	else if (param == 'u')
		return ((ft_putunsigned(va_arg(var, unsigned int))));
	else if (param == 'p')
		return (ft_putadress(va_arg(var, uintptr_t)));
	else if (param == 'X' || param == 'x')
		return ((ft_puthexa(va_arg(var, unsigned int), param)));
	else if (param == '%')
		return ((ft_putchar_fd(('%'), 1)));
	else
		return (-1);
}

int	ft_printf(const char *param, ...)
{
	int		i;
	int		len;
	va_list	var;

	va_start(var, param);
	i = 0;
	len = 0;
	if (param == NULL)
		return (0);
	while (param[i] != '\0')
	{
		if (param[(i)] == '%' && ft_strchr("csdixXpu%", param[(i + 1)]))
		{
			len += ft_param(var, param[(i + 1)]);
			i++;
		}
		else
			len += ft_putchar_fd(param[i], 1);
		i++;
	}
	va_end(var);
	return (len);
}
//* 1.ecrire avec write chaque caractere de l'index jsuqua qu'on trouve un %
//* 2.ne plus ecrire mais regarder d'un de plus dans l'index
//* 3.voir (if) le type d'élement a cet position (c, s, d, i, X, u, p, x, %)
//* 4.ecrire les caracteres selon le type d'element
//! 4.1 ne pas oublier de count le nbs de caractere qui
//! est imprimer et ajouter au count initial
//* 5. rvenir a 1. et continuer jsuquau prochain %
//? %c: Print a single character.
//? %s: Print a null-terminated string.
//? %d or %i: Print a signed integer.
//? %X or %x: Print an unsigned integer in hexadecimal format.
//? %p: Print the address of a pointer in hexadecimal format.
//? %u: Print an unsigned integer in decimal format.
//? %%: Print a percent sign ‘%’.
