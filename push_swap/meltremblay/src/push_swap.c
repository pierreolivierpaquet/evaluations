/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:29:20 by meltremb          #+#    #+#             */
/*   Updated: 2023/04/27 11:09:02 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	three_sort(t_data *d)
{
	if (!is_sorted(d))
	{
		if (d->a->first->index == 1 || d->a->first->next->index == 1)
			rotate_until(d, d->a, 'a', look_for_range(d, 2, 2, 2));
		if (d->a->first->index > d->a->first->next->index)
			swap(d, 'a');
		if (d->a->first->index != 1)
			rotate_until(d, d->a, 'a', look_for_range(d, 1, 1, 1));
	}
}

void	six_sort(t_data *d)
{
	int	smol;
	int	tiny;

	smol = smollest(d->a);
	tiny = smol + 1;
	if (!is_sorted(d))
	{
		if (d->a->first->index == smol || d->a->first->next->index == smol)
			rotate_until(d, d->a, 'a', look_for_range(d, tiny, tiny, tiny));
		if (d->a->first->index > d->a->first->next->index)
			swap(d, 'a');
		if (d->a->first->index != smol)
			rotate_until(d, d->a, 'a', look_for_range(d, smol, smol, smol));
	}
}

void	quick_sort(t_data *d)
{
	int	i;
	int	min;
	int	max;

	min = 1;
	max = d->range;
	i = 0;
	if (!is_sorted(d))
	{
		while (i++ < max && d->a->size > d->b->size + 1)
		{
			rotate_until(d, d->a, 'a', look_for_range(d, min, i, i));
			push(d, 'b');
			if (d->b->size > 1 && d->b->first->index < d->b->first->next->index)
				swap(d, 'b');
		}
		six_sort(d);
		push_back(d);
	}
}

void	push_swap(t_data *d)
{
	int	min;
	int	max;
	int	i;

	min = 1;
	max = d->range;
	i = 0;
	if (!is_sorted(d))
	{
		while (i < (d->a->size + d->b->size))
		{
			while (i++ < max)
			{
				rotate_until(d, d->a, 'a', look_for_range(d, min, max, i));
				push(d, 'b');
			}
			min = i;
			i--;
			max = (min + d->range) - 1;
			if (max > d->a->size + d->b->size)
				max = d->a->size + d->b->size;
		}
		push_back(d);
	}
}

int	main(int argc, char **argv)
{
	t_data	*d;

	d = ft_calloc(1, sizeof(t_data));
	init_piles(d);
	if (!make_pile(d, argc, argv))
	{
		dbl_lst_free(d->a);
		free(d->a);
		free(d->b);
		free(d);
		ft_exit("Error");
	}
	if (d->a->size <= 3)
		three_sort(d);
	else if (d->a->size <= 6)
		quick_sort(d);
	else
		push_swap(d);
	dbl_lst_free(d->a);
	free(d->a);
	free(d->b);
	free(d);
	return (0);
}
