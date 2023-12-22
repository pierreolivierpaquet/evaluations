/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:12:09 by mkramer           #+#    #+#             */
/*   Updated: 2023/09/19 19:12:09 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sends the stack to the desired function

void	sort_stack(t_stacks *stacks)
{
	if (stacks->count_a <= 3)
		sort_3(stacks);
	else if (stacks->count_a <= 5)
		sort_5(stacks);
	else
		global_sort(stacks);
}

int	main(int ac, char **av)
{
	t_data		*new;
	t_stacks	*stacks;

	if (ac < 2)
		exit(1);
	new = (t_data *)malloc(sizeof(t_data));
	free_new(new);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	free_stacks(stacks);
	to_null(stacks, new);
	if (is_valid(ac, av))
	{
		break_2_array(ac, av, new);
		is_doubles(new, stacks);
		if (is_sorted(new))
		{
			init_stack(new, stacks);
			sort_stack(stacks);
			free_stack(stacks);
		}
	}
	free(new);
	free(stacks);
	return (0);
}
