/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:10:50 by meltremb          #+#    #+#             */
/*   Updated: 2022/04/22 12:44:03 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Reading this thing is probably what being drunk feels like or so I've been 
 * told, but it passes every test so you're a BIG NERD Justine. you make a
 * first string to cut the beginning, you count it until you arrive at \0
 * && is no longer in set with the great notin function. once you got your
 * beginning to cut you go for the last, start at the end -1 for the lil \0 and
 * decrement with the same logic as first. you then use the substr to create
 * a string extracted from first, starting at 0 and  with the length of
 * last - first. Is there a simpler way to do this? Probably, but i wrote
 * this at 12 am on a 15 hour streak so gimme a break. */

#include"libft.h"

int	notin(char c, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	char	*first;
	char	*last;

	if (!s1 || !set)
		return (0);
	first = (char *)s1;
	last = first + ft_strlen(s1);
	while (*first && notin(*first, set))
		first++;
	while (first < last && notin(*(last - 1), set))
		last--;
	ret = ft_substr(first, 0, last - first);
	return (ret);
}
/* Lil function to test if each character of set is or not in the set
 * (ex: set = xyz, go with x, then y, then z) return 1 if yes, 0 if not */

int	notin(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}
