/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:39:15 by meltremb          #+#    #+#             */
/*   Updated: 2022/04/21 15:22:25 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Pretty much the same as strlcpy, except it returns the length of src plus
 * dest. I think. These functions are weird bro. */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dst[j] && j < dstsize)
		j++;
	i = j;
	while (src[j - i] && (j + 1) < dstsize)
	{
		dst[j] = src[j - i];
		j++;
	}
	if (i < dstsize)
		dst[j] = '\0';
	return (i + ft_strlen(src));
}
