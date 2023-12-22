/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:33:36 by meltremb          #+#    #+#             */
/*   Updated: 2023/03/16 11:09:01 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_exit(char *message)
{
	int	i;

	i = -1;
	if (ft_strlen(message) > 0)
	{
		while (message[++i])
			write(2, &message[i], 1);
		write(2, "\n", 1);
	}
	close(0);
	close(1);
	close(2);
	exit(1);
}
