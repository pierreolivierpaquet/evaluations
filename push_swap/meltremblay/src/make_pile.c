/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:19:22 by meltremb          #+#    #+#             */
/*   Updated: 2023/04/27 12:18:38 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_piles(t_data *d)
{
	d->a = ft_calloc(1, sizeof(t_pile));
	d->b = ft_calloc(1, sizeof(t_pile));
}

void	indexer(t_pile *any)
{
	t_node	*temp;
	t_node	*smolguy;
	int		index;

	smolguy = any->first;
	while (smolguy)
	{
		temp = any->first;
		index = 1;
		while (temp)
		{
			if (smolguy->content > temp->content)
				index++;
			temp = temp->next;
		}
		smolguy->index = index;
		smolguy = smolguy->next;
	}
}

int	arg_check(char *args)
{
	int		i;

	i = 0;
	if (!too_long(args))
		return (0);
	if (!ft_str_isdigit(args))
		return (0);
	return (1);
}

int	check_doubles(t_pile *any)
{
	t_node	*temp;
	t_node	*first;
	int		doubles;

	temp = any->first;
	while (temp)
	{
		doubles = 0;
		first = temp;
		while (first)
		{
			if (first->content == temp->content)
				doubles++;
			if (doubles >= 2)
				return (0);
			first = first->next;
		}
		temp = temp->next;
	}
	return (1);
}

int	make_pile(t_data *d, int argc, char **argv)
{
	int		i;
	int		k;
	char	**args;

	i = 0;
	while (argv[++i] && i < argc)
	{
		k = -1;
		args = ft_split(argv[i], ' ');
		while (args[++k])
		{
			if (!arg_check(args[k]))
			{
				ft_free_array((void ***) &args);
				return (0);
			}
			dbl_lst_add_back(d->a, ft_atoi(args[k]));
		}
		ft_free_array((void ***) &args);
	}
	if (!check_doubles(d->a))
		return (0);
	indexer(d->a);
	d->range = root(d->a->size);
	return (1);
}
