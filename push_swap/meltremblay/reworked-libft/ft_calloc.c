/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:41:37 by meltremb          #+#    #+#             */
/*   Updated: 2022/04/05 13:34:00 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Here's why bzero is useful, that's about it. rip the nerds who set the
 * bytes to zero manually. make pointer, allocate space, set all bytes to zero,
 * rinse and repeat. */
#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
