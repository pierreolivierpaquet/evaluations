/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:28:28 by rofontai          #+#    #+#             */
/*   Updated: 2023/03/07 10:19:39 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	f_check_sort(t_lst *list)
{
	while (list->next != NULL)
	{
		if (list->next->nombre < list->nombre)
			return (0);
		list = list->next;
	}
	return (1);
}

void	f_sort(t_stack *pile)
{
	if (f_check_sort(pile->a) == 1)
		return ;
	if (pile->size_a == 2)
		f_swap_a(pile);
	else if (pile->size_a == 3)
		f_algo_3(pile);
	else if (pile->size_a > 3)
		f_algo_big(pile);
}

void	f_algo_3(t_stack *pile)
{
	while (f_check_sort(pile->a) == 0)
	{
		if (pile->a == f_search_top_index(pile->a))
			f_rotate_a(pile);
		else
			f_swap_a(pile);
	}
}
