/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:28:35 by rofontai          #+#    #+#             */
/*   Updated: 2023/03/07 14:07:33 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_check_double(t_stack *pile, t_lst *node)
{
	t_lst	*temp;

	while (node->next != NULL)
	{
		temp = node->next;
		while (temp)
		{
			if (temp->nombre == node->nombre)
				f_error("Error\n", &pile, 0);
			temp = temp->next;
		}
		node = node->next;
	}
}

t_stack	*f_pars(int argc, char **argv)
{
	t_stack	*pile;
	char	**tab;
	int		i;

	i = 0;
	pile = f_init();
	if (argc < 2)
		f_error(0, &pile, 0);
	if (argc == 2)
	{
		tab = ft_split(argv[1], 32);
		add_list_split(tab, pile, i);
		ft_free_tab(tab);
	}
	if (argc > 2)
	{
		i = 1;
		add_list(argv, pile, i);
	}
	f_check_double(pile, pile->a);
	return (pile);
}

void	f_index(t_stack *pile)
{
	t_lst	*temp;
	int		size;

	temp = pile->a;
	size = pile->size_a;
	while (size != 0)
	{
		pile->a = f_search_top(pile->a);
		pile->a->index = size--;
		pile->a = temp;
	}
}

void	add_list_split(char **str, t_stack *pile, int i)
{
	while (str[i])
	{
		f_addback_node((&pile->a),
			f_new_node((f_number(str[i++], pile, str)), pile));
		pile->size_a++;
	}
}

void	add_list(char **str, t_stack *pile, int i)
{
	while (str[i])
	{
		f_addback_node((&pile->a),
			f_new_node((f_number(str[i++], pile, 0)), pile));
		pile->size_a++;
	}
}
