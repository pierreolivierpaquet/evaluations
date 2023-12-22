/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:24:17 by meltremb          #+#    #+#             */
/*   Updated: 2023/03/07 16:40:41 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_free_null(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void	ft_free_array(void	***array)
{
	int	i;

	if (*array)
	{
		i = -1;
		while ((*array)[++i])
			free((*array)[i]);
		free(*array);
		*array = NULL;
	}
}
