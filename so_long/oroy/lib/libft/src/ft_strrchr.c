/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:57:58 by oroy              #+#    #+#             */
/*   Updated: 2023/08/09 19:21:45 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	while (s_len)
	{
		if (*(s + s_len) == (char)c)
			return ((char *)(s + s_len));
		s_len--;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
