/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:12:20 by mkramer           #+#    #+#             */
/*   Updated: 2023/09/19 19:12:20 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// move all elements one step up, the top one goes down

void	ft_ra(t_stack **a, int i)
{
	t_stack	*first_list;
	t_stack	*rotate_list;
	t_stack	*last_list;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	rotate_list = *a;
	first_list = (*a)->next;
	last_list = *a;
	while (last_list->next != NULL)
		last_list = last_list->next;
	rotate_list->next = NULL;
	last_list->next = rotate_list;
	*a = first_list;
	if (i == 1)
		write(1, "ra\n", 3);
}

// move all elements one step up, the top one goes down

void	ft_rb(t_stack **b, int i)
{
	t_stack	*first_list;
	t_stack	*rotate_list;
	t_stack	*last_list;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	rotate_list = *b;
	first_list = (*b)->next;
	last_list = *b;
	while (last_list->next != NULL)
		last_list = last_list->next;
	rotate_list->next = NULL;
	last_list->next = rotate_list;
	*b = first_list;
	if (i == 1)
		write(1, "rb\n", 3);
}

// ra and rb at the same time

void	ft_rr(t_stacks *s, int i)
{
	if (i == 1)
		write(1, "rr\n", 3);
	ft_ra(&s->a, 0);
	ft_rb(&s->b, 0);
}

// reverse rotate. all elements go down on 1 step. the bottom goes to the top

void	ft_rra(t_stack **a, int i)
{
	t_stack		*first_list;
	t_stack		*rotate_list;
	t_stack		*penult_lst;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	first_list = *a;
	penult_lst = *a;
	while (penult_lst->next->next != NULL)
		penult_lst = penult_lst->next;
	rotate_list = penult_lst->next;
	penult_lst->next = NULL;
	rotate_list->next = first_list;
	*a = rotate_list;
	if (i == 1)
		write(1, "rra\n", 4);
}

// reverse rotate. all elements go down on 1 step. the bottom goes to the top

void	ft_rrb(t_stack **b, int i)
{
	t_stack		*first_list;
	t_stack		*rotate_list;
	t_stack		*penult_lst;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	first_list = *b;
	penult_lst = *b;
	while (penult_lst->next->next != NULL)
		penult_lst = penult_lst->next;
	rotate_list = penult_lst->next;
	penult_lst->next = NULL;
	rotate_list->next = first_list;
	*b = rotate_list;
	if (i == 1)
		write(1, "rrb\n", 4);
}
