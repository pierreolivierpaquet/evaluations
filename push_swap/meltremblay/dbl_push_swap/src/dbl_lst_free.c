/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lst_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:10:54 by meltremb          #+#    #+#             */
/*   Updated: 2023/04/21 15:28:27 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/dbl_extension_libft.h"

void	dbl_lst_free(t_pile *list)
{
	t_node	*temp;
	t_node	*next;

	next = list->first;
	while (next)
	{
		temp = next;
		next = next->next;
		free(temp);
	}
}
