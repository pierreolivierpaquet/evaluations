/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:36:08 by meltremb          #+#    #+#             */
/*   Updated: 2022/04/05 14:02:07 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* You'd THINK this functions makes a copy and returns a string, but nope! it
 * copies the source to dest, and then returns the length of that string (src)
 * or dstsize, whatever is shorter. oh also it null terminates dst. safer
 * strcpy if you don't know what you're doing ig but nothing beats my beloved
 * strlen ~ uwu.*/

#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (--dstsize && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
