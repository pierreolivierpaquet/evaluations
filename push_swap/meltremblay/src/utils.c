/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:08:08 by meltremb          #+#    #+#             */
/*   Updated: 2023/04/21 13:23:25 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_until(t_data *d, t_pile *any, char type, int count)
{
	if (count > 0)
	{
		while (count-- > 0)
			rotate(d, any, type);
	}
	else if (count < 0)
	{
		while (count++ < 0)
			reverse_rotate(d, any, type);
	}
}

int	is_sorted(t_data *d)
{
	t_node	*temp;
	int		i;

	temp = d->a->first;
	i = 1;
	while (temp)
	{
		if (temp->index != i)
			return (0);
		i++;
		temp = temp->next;
	}
	return (1);
}

int	root(int size)
{
	int	i;

	i = 1;
	while (i * i < size)
		i++;
	return (i);
}

int	smollest(t_pile *any)
{
	t_node	*temp;
	int		smollest;
	int		i;

	temp = any->first;
	smollest = any->first->index;
	i = 0;
	while (temp && ++i <= any->size)
	{
		if (temp->index < smollest)
			smollest = temp->index;
		temp = temp->next;
	}
	return (smollest);
}

int	smallest_range(int prev, int new)
{
	int	temp_prev;
	int	temp;

	temp = new;
	temp_prev = prev;
	if (prev < 0)
		temp_prev = prev * -1;
	if (new < 0)
		temp = new * -1;
	if (temp < temp_prev)
		return (new);
	else
		return (prev);
}
