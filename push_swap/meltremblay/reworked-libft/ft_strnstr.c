/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:17:11 by meltremb          #+#    #+#             */
/*   Updated: 2022/04/05 13:30:10 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* finding a needle in a haystack, as long as you're under len amount of lil
 * fibers of hay searched. You really wanna look through a whole haystack? .*/

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needlen;

	i = 0;
	needlen = ft_strlen(needle);
	if (!(*needle))
		return ((char *)haystack);
	while (*haystack && (i < len))
	{
		if ((ft_strncmp(haystack, needle, needlen) == 0)
			&& (i + needlen <= len))
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
