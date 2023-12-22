/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:20:44 by meltremb          #+#    #+#             */
/*   Updated: 2022/04/12 12:29:22 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Welcome to hell, Lists. this one creates a new element in a list (pikachu)
 * It's allocated the space of a t_list variable defined in the libft. if the
 * allocation fails, NULL is returned. Then some witchcraft happens. the content
 * of pikachu is sent to the content when the function is called, and the next
 * is set to NULL, so to be defined later on. pikachu is returned.*/
#include"libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*pikachu;

	pikachu = malloc(sizeof(t_list));
	if (!pikachu)
		return (NULL);
	pikachu->content = content;
	pikachu->next = NULL;
	return (pikachu);
}
