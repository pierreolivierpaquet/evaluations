/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:19:56 by meltremb          #+#    #+#             */
/*   Updated: 2023/04/27 11:55:54 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	counter(t_pile *any, int value)
{
	int		countdown;
	int		countup;
	t_node	*tempfirst;
	t_node	*templast;

	countdown = 0;
	countup = -1;
	tempfirst = any->first;
	templast = any->last;
	while ((tempfirst && tempfirst->index != value)
		&& (templast && templast->index != value) && (countdown < any->size))
	{
		countdown++;
		countup--;
		tempfirst = tempfirst->next;
		templast = templast->prev;
	}
	if (tempfirst && tempfirst->index == value)
		return (countdown);
	else if (templast && templast->index == value)
		return (countup);
	else if (countdown == (countup * -1))
		return (countdown);
	else
		return (INT_MAX);
}

int	look_for_range(t_data *d, int min, int max, int i)
{
	int	nb_moves;
	int	prev_nb_moves;
	int	j;

	prev_nb_moves = counter(d->a, i);
	j = min - 1;
	while (j++ < max)
	{
		nb_moves = counter(d->a, j);
		prev_nb_moves = smallest_range(prev_nb_moves, nb_moves);
	}
	return (prev_nb_moves);
}

void	push_back(t_data *d)
{
	int	i;

	i = d->b->size + 1;
	while (--i > 0)
	{
		if (d->b->first->index == i)
			push(d, 'a');
		else
		{
			rotate_until(d, d->b, 'b', counter(d->b, i));
			push(d, 'a');
		}
	}
}

int	too_long(char *str)
{
	if (str[0] == '-')
	{
		if (ft_strlen(str) > 11)
			return (0);
		else if (ft_strlen(str) < 11)
			return (1);
		else if (ft_strncmp(str, "-2147483648", 11) > 0)
			return (0);
	}
	else
	{
		if (ft_strlen(str) > 10)
			return (0);
		else if (ft_strlen(str) < 10)
			return (1);
		else if (ft_strncmp(str, "2147483647", 10) > 0)
			return (0);
	}
	return (1);
}
