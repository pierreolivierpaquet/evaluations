/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:48:34 by oroy              #+#    #+#             */
/*   Updated: 2023/08/09 19:21:45 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*position;
	t_list	*head;

	if (!lst || !del)
		return ;
	head = NULL;
	position = *lst;
	while (position)
	{
		head = position->next;
		ft_lstdelone(position, del);
		position = head;
	}
	*lst = NULL;
}
