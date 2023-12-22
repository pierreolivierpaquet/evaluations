/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:45:08 by meltremb          #+#    #+#             */
/*   Updated: 2022/04/05 13:03:03 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Same as memcpy, you got some bites in src you want to put in dest for a
 * given length, and you do it. except this one will make sure you got room
 * in your dest or something like that, whereas memcpy would just shit in your
 * hands. */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cdest;
	char	*csrc;

	cdest = (char *) dst;
	csrc = (char *) src;
	if (!dst && !src)
		return (NULL);
	if (cdest > csrc)
		while (len--)
			cdest[len] = csrc[len];
	else
	{
		while (len--)
		{
			*cdest++ = *csrc++;
		}
	}
	return (dst);
}
