/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:11:59 by mkramer           #+#    #+#             */
/*   Updated: 2023/09/19 19:11:59 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check the string for validity

#include "push_swap.h"

int	is_valid(int ac, char **av)
{
	int	i;
	int	res;

	res = 0;
	i = 1;
	while (i < ac)
	{
		if (ft_only_spaces(av[i]))
		{
			is_num_available(av[i]);
			is_string_valid(av[i]);
			res = 1;
		}
		i++;
	}
	return (res);
}

// checking the string if it consists of digits

void	is_num_available(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return ;
		i++;
	}
	ft_error();
}

// check the string for validity, only digits accepted

void	is_string_valid(const char *str)
{
	size_t	i;
	int		num;
	int		sgn;

	i = 0;
	num = 0;
	sgn = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			num++;
		else if (str[i] == 32 || str[i] == 9)
		{
			if (sgn != 0 && num == 0)
				ft_error();
			num = 0;
			sgn = 0;
		}
		else if (((str[i] == '+' || str[i] == '-')
				&& (sgn == 0 && num == 0)) && (str[i + 1]))
			sgn++;
		else
			ft_error();
		i++;
	}
}

// checking doubles in struct

void	is_doubles(t_data *new, t_stacks *stacks)
{
	int			*dup;

	dup = (int *)malloc(sizeof(int) * (new->count_element));
	if (!dup)
		exit(1);
	dup = ft_intcpy(dup, new->a, new->count_element);
	ft_quick_sort(dup, 0, new->count_element - 1);
	search_doubles(dup, new->count_element - 1);
	stacks->count_a = new->count_element;
	stacks->count_b = 0;
	stacks->min = dup[0];
	stacks->med = dup[new->count_element / 2];
	stacks->max = dup[new->count_element - 1];
	free(dup);
}

// basic search doubles

void	search_doubles(const int *dup, int count)
{
	int	i;

	i = 0;
	while (i != count)
	{
		if (dup[i] == dup[i + 1])
			ft_error();
		i++;
	}
}
