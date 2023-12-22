/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:12:07 by mkramer           #+#    #+#             */
/*   Updated: 2023/09/19 19:12:07 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// recursive quick sort

void	ft_quick_sort(int *arr, int start, int end)
{
	int	q;

	if (start < end)
	{
		q = breaking(arr, start, end);
		ft_quick_sort(arr, start, q - 1);
		ft_quick_sort(arr, q + 1, end);
	}
}

// breaking the array. The main part of sorting is here	

int	breaking(int *arr, int start, int end)
{
	int	mid;
	int	i;
	int	tmp;
	int	j;

	mid = arr[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (arr[j] <= mid)
		{
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
		j++;
	}
	tmp = arr[i + 1];
	arr[i + 1] = arr[end];
	arr[end] = tmp;
	return (i + 1);
}
