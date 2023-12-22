/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:04:12 by meltremb          #+#    #+#             */
/*   Updated: 2022/04/05 11:19:29 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* This one is no joke. would be useful if memmove wasn't a thing. this one
 * copies n letters (or bytes if you're a BIG NERD) from the source string and
 * puts them in the dst. it doesn't take into account if the sizes of src and
 * dst are ok to actually copy them so that's why this is pretty useless cuz 
 * memmove exists. */
#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*csrc;
	char	*cdest;
	size_t	i;

	csrc = (char *) src;
	cdest = (char *) dst;
	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dst);
}
