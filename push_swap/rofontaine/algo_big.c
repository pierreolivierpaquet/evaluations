/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:47:19 by rofontai          #+#    #+#             */
/*   Updated: 2023/03/07 09:12:30 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_algo_big(t_stack *pile)
{
	int	i;
	int	div;

	i = pile->size_a;
	div = i / 4;
	transfert_pile_b(pile, i, div);
	f_algo_3(pile);
	while (pile->size_a != i && pile->b != 0)
	{
		while (pile->b->index > pile->a->index)
		{
			f_rotate_a(pile);
		}
		while (pile->b->index < f_last_node(pile->a)->index)
		{
			if (pile->a->index < f_last_node(pile->a)->index)
				break ;
			f_reverse_a(pile);
		}
		f_push_a(pile);
	}
	while (f_check_sort(pile->a) == 0)
	{
		f_reverse_a(pile);
	}
}

void	transfert_pile_b(t_stack *pile, int i, int div)
{
	pile->med_a = pile->size_a / 2;
	while (pile->size_a > 3 && div > 0)
	{
		while (pile->size_a != div * 2 && pile->size_a > 3)
		{
			if ((pile->a->index >= div) && (pile->a->index < pile->med_a))
			{
				f_push_b(pile);
				if (pile->size_b > 1)
					f_rotate_b(pile);
			}
			else if ((pile->a->index >= pile->med_a)
				&& (pile->a->index <= i - div))
			{
				f_push_b(pile);
				if (pile->b->next != NULL
					&& pile->b->index < pile->b->next->index)
					f_swap_b(pile);
			}
			else
				f_rotate_a(pile);
		}
		div = div / 2;
	}
}
