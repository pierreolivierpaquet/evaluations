/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 08:38:53 by rofontai          #+#    #+#             */
/*   Updated: 2023/03/07 08:43:03 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_swap_a(t_stack *pile)
{
	if (pile->a == NULL)
		return ;
	ft_swap(&pile->a->nombre, &pile->a->next->nombre);
	ft_swap(&pile->a->index, &pile->a->next->index);
	printf("sa\n");
}

void	f_swap_b(t_stack *pile)
{
	if (pile->b == NULL || pile->size_b == 1)
		return ;
	ft_swap(&pile->b->nombre, &pile->b->next->nombre);
	ft_swap(&pile->b->index, &pile->b->next->index);
	printf("sb\n");
}

void	f_reverse_a(t_stack *pile)
{
	t_lst	*temp;
	t_lst	*last;
	t_lst	*be_last;

	temp = pile->a;
	be_last = f_be_last_node(pile->a);
	last = f_last_node(pile->a);
	last->next = temp;
	be_last->next = NULL;
	pile->a = last;
	printf("rra\n");
}

void	f_reverse_b(t_stack *pile)
{
	t_lst	*temp;
	t_lst	*last;
	t_lst	*be_last;

	if (pile->b == NULL)
		return ;
	temp = pile->b;
	be_last = f_be_last_node(pile->b);
	last = f_last_node(pile->b);
	last->next = temp;
	be_last->next = NULL;
	pile->b = last;
	printf("rrb\n");
}
