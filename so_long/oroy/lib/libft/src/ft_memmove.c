/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:04:32 by oroy              #+#    #+#             */
/*   Updated: 2023/08/09 19:21:45 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst || !src)
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (*s < *d)
		while (len--)
			*(d + len) = *(s + len);
	else
		while (len--)
			*d++ = *s++;
	return (dst);
}
