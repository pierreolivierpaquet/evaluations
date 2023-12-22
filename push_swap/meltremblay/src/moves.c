/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 09:05:47 by meltremb          #+#    #+#             */
/*   Updated: 2023/04/21 13:31:58 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_data *d, char type)
{
	int		value;

	if ((type == 'a' || type == 's') && d->a->size > 1)
	{
		value = d->a->first->index;
		d->a->first->index = d->a->first->next->index;
		d->a->first->next->index = value;
		if (type == 'a')
			write (1, "sa\n", 3);
	}
	if ((type == 'b' || type == 's') && d->b->size > 1)
	{
		value = d->b->first->index;
		d->b->first->index = d->b->first->next->index;
		d->b->first->next->index = value;
		if (type == 'b')
			write (1, "sb\n", 3);
	}
	if (type == 's')
		write (1, "ss\n", 3);
}

void	p(t_pile *a, t_pile *b)
{
	t_node	*temp;

	a->size++;
	b->size--;
	temp = b->first;
	b->first = b->first->next;
	if (temp->next)
		temp->next->prev = NULL;
	if (a->first)
	{
		temp->next = a->first;
		a->first->prev = temp;
	}
	else
	{
		temp->next = NULL;
		a->last = temp;
	}
	a->first = temp;
}

void	push(t_data *d, char type)
{
	if (type == 'a' && d->b->size > 0)
	{
		p(d->a, d->b);
		write (1, "pa\n", 3);
	}
	if (type == 'b' && d->a->size > 0)
	{
		p(d->b, d->a);
		write (1, "pb\n", 3);
	}
}

void	rotate(t_data *d, t_pile *any, char type)
{
	t_node	*temp;

	temp = any->first;
	temp->prev = any->last;
	any->first = temp->next;
	temp->next = NULL;
	any->first->prev = NULL;
	any->last->next = temp;
	any->last = temp;
	if (type == 'a')
		write (1, "ra\n", 3);
	else if (type == 'b')
		write (1, "rb\n", 3);
	else if (type == 'r')
		rotate(d, d->b, 'd');
	else if (type == 'd')
		write (1, "rr\n", 3);
}

void	reverse_rotate(t_data *d, t_pile *any, char type)
{
	t_node	*temp;

	temp = any->last;
	any->last = temp->prev;
	any->last->next = NULL;
	temp->prev = NULL;
	temp->next = any->first;
	any->first->prev = temp;
	any->first = temp;
	if (type == 'a')
		write (1, "rra\n", 4);
	else if (type == 'b')
		write (1, "rrb\n", 4);
	else if (type == 'r')
		reverse_rotate(d, d->b, 'd');
	else if (type == 'd')
		write (1, "rrr\n", 4);
}
