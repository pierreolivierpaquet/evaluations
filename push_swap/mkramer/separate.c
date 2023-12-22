/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:12:05 by mkramer           #+#    #+#             */
/*   Updated: 2023/09/19 19:12:05 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// breaking the string to array

void	break_2_array(int ac, char **av, t_data *new)
{
	int		p;
	int		i;
	int		*buff;
	char	**arr;
	int		cnt_elem;

	i = 1;
	while (i < ac)
	{
		p = -1;
		cnt_elem = ft_countword(av[i]);
		arr = ft_strsplit(av[i], cnt_elem);
		buff = (int *)malloc(sizeof(int) * (cnt_elem));
		if (!buff)
			exit(1);
		while (cnt_elem > ++p)
		{
			buff[p] = ft_atoi(arr[p]);
			free(arr[p]);
		}
		free(arr);
		fill_stack(new, buff, cnt_elem);
		i++;
	}
}

// filling up the stack (new->a (array in t_data)) n-count times

void	fill_stack(t_data *new, int *buff, int count)
{
	int	i;

	i = -1;
	while (count > ++i)
		new->a[new->count_element + i] = buff[i];
	new->count_element += count;
	free(buff);
}
