/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:21:23 by meltremb          #+#    #+#             */
/*   Updated: 2022/04/05 11:12:17 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* This one gets a bit complicated. basically some witchcraft happens, that's
 * when you learn you can temporarily recast variables as something else (woah)
 * and it's gonna change your life. anyway it changes some bytes of the value c
 * and puts them in the string b, for the length of len. wooosh */

#include"libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*a;

	a = (char *)b;
	while (len)
	{
		*a = (char) c;
		a++;
		len --;
	}
	return (b);
}
