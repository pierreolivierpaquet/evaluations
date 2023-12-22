/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:17:34 by rofontai          #+#    #+#             */
/*   Updated: 2023/03/13 10:34:25 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	f_number(char *str, t_stack *pile, char **tab)
{
	long	nb;
	int		neg;
	int		i;

	neg = 1;
	i = 0;
	nb = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' && !ft_isdigit(str[i + 1]))
			f_error("Error\n", &pile, tab);
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		nb = (nb * 10) + (str[i++] - 48);
	nb *= neg;
	if ((i == 0 || str[i] || nb > INT_MAX || nb < INT_MIN))
		f_error("Error\n", &pile, tab);
	return (nb);
}

t_stack	*f_init(void)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->a = NULL;
	new->b = NULL;
	new->med_a = 0;
	new->med_b = 0;
	new->size_a = 0;
	new->size_b = 0;
	return (new);
}

t_lst	*f_search_top_index(t_lst *pile)
{
	t_lst	*up;

	up = pile;
	while (pile)
	{
		if ((up->nombre < pile->nombre))
				up = pile;
		pile = pile->next;
	}
	return (up);
}

void	f_addfront_node(t_lst **lst, t_lst *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

int	f_nombre_mouv(t_lst *list)
{
	int		i;
	t_lst	*post;

	i = 0;
	post = f_search_top_index(list);
	while (list != post)
	{
		i ++;
		list = list->next;
	}
	return (i);
}
