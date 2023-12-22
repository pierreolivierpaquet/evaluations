/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:26:01 by meltremb          #+#    #+#             */
/*   Updated: 2022/04/05 13:28:13 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   ___----------v there it is (first occurence, but with memory)
 * 	|	s = "The cake is a lie"		    c = 'a'_______   ____
 * 	|__________________________	    				  | |    |
 *						       |					  |_|____|
 *							   |________________________| 		
 *	the - 1 in the return is probably cuz of the \0 because i guess.
 *	also as long as you're within n bytes. */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *) s;
	while (n--)
		if (*str++ == (unsigned char) c)
			return (str - 1);
	return (NULL);
}
