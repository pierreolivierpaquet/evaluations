/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:12:18 by mkramer           #+#    #+#             */
/*   Updated: 2023/09/19 19:12:18 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	actions(char *line, t_stacks *s)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_sa(s->a, 0);
	else if (ft_strcmp(line, "sb") == 0)
		ft_sb(s->b, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ft_ss(s, 0);
	else if (ft_strcmp(line, "pa") == 0)
		ft_pa(s, 0);
	else if (ft_strcmp(line, "pb") == 0)
		ft_pb(s, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ft_ra(&s->a, 0);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rb(&s->b, 0);
	else if (ft_strcmp(line, "rr") == 0)
		ft_rr(s, 0);
	else if (ft_strcmp(line, "rra") == 0)
		ft_rra(&s->a, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rrb(&s->b, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rrr(s, 0);
	else
		ft_error();
}

// wait input in command line and fetch the input
// to the processing func

void	read_action(t_stacks *s)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		actions(line, s);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

// check whether the stack is sorted

int	is_stack_sorted(t_stacks *s)
{
	int		i;
	int		buff;
	t_stack	*save;

	i = 0;
	save = s->a;
	while (i < (s->count_a - 1))
	{
		buff = s->a->data;
		s->a = s->a->next;
		if (buff > s->a->data)
		{
			s->a = save;
			return (0);
		}
		i++;
	}
	s->a = save;
	return (1);
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
		init_stack(new, stacks);
		read_action(stacks);
		if ((is_stack_sorted(stacks)) && stacks->count_b == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free_stack(stacks);
	free(new);
	free(stacks);
	return (0);
}
