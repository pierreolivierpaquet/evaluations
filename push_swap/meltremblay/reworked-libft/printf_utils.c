/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:11:19 by meltremb          #+#    #+#             */
/*   Updated: 2022/05/24 15:48:53 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	canprintpls_uwu(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	upper_string(int nb)
{
	if (nb >= 'a' && nb <= 'z')
		nb = nb - 32;
	return (nb);
}
