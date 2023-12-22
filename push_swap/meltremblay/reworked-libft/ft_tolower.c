/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:27:40 by meltremb          #+#    #+#             */
/*   Updated: 2022/04/05 13:08:04 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* I sure hope you don't need to read this to understand what that one does. 
 * In case you do, uppercase--->lowercase. straight up witchcraft. */

#include"libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
