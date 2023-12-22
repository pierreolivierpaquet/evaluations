/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:54:58 by meltremb          #+#    #+#             */
/*   Updated: 2022/04/05 11:01:24 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Omfg, an other function to tell if a character is a letter, but this time
 * min or maj. are you even gonna use these functions ever? */

#include"libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
