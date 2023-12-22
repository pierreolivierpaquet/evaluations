/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:24:46 by meltremb          #+#    #+#             */
/*   Updated: 2022/04/05 13:06:50 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Very high level function there. to use carefully not to get confused. /s
 * makes lowercase letters uppercase. that's about it. */

#include"libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
