/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:02:41 by rofontai          #+#    #+#             */
/*   Updated: 2023/03/13 10:34:03 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_free_list(t_lst **list)
{
	t_lst	*temp;

	if (!*list || !list)
		return ;
	while (*list)
	{
		temp = (*list)->next;
		free(*list);
		(*list) = temp;
	}
	*list = NULL;
}

void	f_free_stack(t_stack **pile)
{
	if (!*pile || !pile)
		return ;
	free(*pile);
	pile = NULL;
}

void	f_error(char *str, t_stack **pile, char **tab)
{
	if ((*pile)->a)
		f_free_list(&(*pile)->a);
	if ((*pile)->b)
		f_free_list(&(*pile)->b);
	if (tab && tab != 0)
		ft_free_tab(tab);
	if (pile)
		f_free_stack(pile);
	write(STDERR_FILENO, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}
