/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:12:15 by mkramer           #+#    #+#             */
/*   Updated: 2023/09/19 19:12:15 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Insertion sort. Prepare the stack for sorting

void	global_sort(t_stacks *stacks)
{
	while (stacks->count_a > 2)
	{
		if (stacks->a->data != stacks->min && stacks->a->data != stacks->max)
		{
			ft_pb(stacks, 1);
			if (stacks->b->data > stacks->med)
				ft_rb(&stacks->b, 1);
		}
		else
			ft_ra(&stacks->a, 1);
	}
	if (stacks->a->data < stacks->a->next->data)
		ft_sa(stacks->a, 1);
	ft_pa(stacks, 1);
	start_sort(stacks);
}
// starting sorting process

void	start_sort(t_stacks *stacks)
{
	t_steps	*step;

	step = (t_steps *)malloc(sizeof(t_steps));
	if (!step)
		exit(1);
	while (stacks->count_b != 0)
	{
		step->count_a = -1;
		step->count_b = -1;
		step->dest_a = 0;
		step->dest_b = 0;
		steps_markup(stacks->a, stacks->count_a);
		steps_markup(stacks->b, stacks->count_b);
		min_steps_2_insert(stacks, step);
		rules_perfom(stacks, step);
	}
	if ((count_2_min(stacks->a, stacks->min)) > stacks->count_a / 2)
	{
		while (stacks->a->data != stacks->min)
			ft_rra(&stacks->a, 1);
	}
	else
		while (stacks->a->data != stacks->min)
			ft_ra(&stacks->a, 1);
	free(step);
}

// marking each stack element with number of steps to reach the top

void	steps_markup(t_stack *b, int count)
{
	int		i;
	int		step;
	t_stack	*buff;

	i = -1;
	step = count / 2;
	buff = b;
	while (++i <= step)
	{
		buff->step = i;
		buff->rotate = 1;
		buff = buff->next;
	}
	if (count % 2 == 0)
		i--;
	while (--i > 0)
	{
		buff->step = i;
		buff->rotate = -1;
		buff = buff->next;
	}
}

// func looks for the element which can fitch with min steps

void	min_steps_2_insert(t_stacks *stacks, t_steps *steps)
{
	int		min_steps;
	t_stack	*first_a;
	t_stack	*first_b;

	min_steps = -1;
	first_a = stacks->a;
	first_b = stacks->b;
	while (stacks->b)
	{
		min_steps = find_place(stacks, stacks->b, steps, min_steps);
		stacks->a = first_a;
		stacks->b = stacks->b->next;
	}
	stacks->b = first_b;
}

// func takes params and use ra, rb... according the params

void	rules_perfom(t_stacks *stacks, t_steps *steps)
{
	while (steps->count_a > 0)
	{
		if (steps->dest_a == 1)
			ft_ra(&stacks->a, 1);
		else
			ft_rra(&stacks->a, 1);
		steps->count_a--;
	}
	while (steps->count_b > 0)
	{
		if (steps->dest_b == 1)
			ft_rb(&stacks->b, 1);
		else
			ft_rrb(&stacks->b, 1);
		steps->count_b--;
	}
	ft_pa(stacks, 1);
}
