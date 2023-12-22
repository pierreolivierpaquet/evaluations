/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:12:13 by mkramer           #+#    #+#             */
/*   Updated: 2023/09/19 19:12:13 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// initiate stack A

void	init_stack(t_data *new, t_stacks *stacks)
{
	stacks->a = create_stack(new->a, new->count_element);
	stacks->b = NULL;
}

// create the stack, getting data from the array

t_stack	*create_stack(const int *buff, int cnt)
{
	int		i;
	t_stack	*new_list;
	t_stack	*elem1;

	i = 0;
	new_list = (t_stack *)malloc(sizeof(t_stack));
	if (!new_list)
		exit(1);
	elem1 = new_list;
	while (i < cnt)
	{
		if (i < cnt - 1)
		{
			new_list->next = (t_stack *)malloc(sizeof(t_stack));
			if (!new_list->next)
				exit(1);
		}
		new_list->data = buff[i];
		if (i == (cnt - 1))
			new_list->next = NULL;
		else
			new_list = new_list->next;
		i++;
	}
	return (elem1);
}

// free memory given to the stack

void	free_stack(t_stacks *stacks)
{
	int		i;
	t_stack	*buff;

	i = 0;
	while (i < stacks->count_a)
	{
		buff = stacks->a;
		stacks->a = stacks->a->next;
		free(buff);
		i++;
	}
	i = 0;
	while (i < stacks->count_b)
	{
		buff = stacks->b;
		stacks->b = stacks->b->next;
		free(buff);
		i++;
	}
}

// put zeros in the struct

void	to_null(t_stacks *stacks, t_data *new)
{
	new->count_element = 0;
	stacks->count_a = 0;
	stacks->count_b = 0;
	stacks->min = 0;
	stacks->max = 0;
	stacks->med = 0;
	stacks->a = NULL;
	stacks->b = NULL;
}
