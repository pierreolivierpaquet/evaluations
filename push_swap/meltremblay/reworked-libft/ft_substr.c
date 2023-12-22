/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:37:37 by meltremb          #+#    #+#             */
/*   Updated: 2023/03/07 15:50:23 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Back in my days, my grandma would like to make us substrings for lunches.
 * I remember we would go "grandma, grandma! pls make us substrings for lunches!
 *  uwu~ >w<" anyway now i have a leg cut off. Here's the recipe for a substring
 *  to warm you up on cold winter days:
 *  take a string, give it a point to start it, increment for given length and
 *  end it with a \0 you simple hoe.*/

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	s2 = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!s2)
		return (0);
	while (i < len && s[start] != '\0')
	{
		s2[i] = s[start];
		start++;
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
