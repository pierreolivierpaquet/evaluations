/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:59:45 by brheaume          #+#    #+#             */
/*   Updated: 2023/06/27 13:02:11 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_verify_args(int ac, char **av)
{
	int			i;
	long long	current;

	i = 2;
	if (ac == 5 || ac == 6)
	{
		if (ft_atol(av[1]) < 0 || ft_atol(av[1]) > 500)
			return (INCORRECT);
		while (i < 5)
		{
			current = ft_atol(av[i]);
			if (current < 60 || current > INT_MAX)
				return (INCORRECT);
			i++;
		}
		if (ac == 6)
		{
			if (ft_atol(av[5]) < 0 || ft_atol(av[5]) > INT_MAX)
				return (INCORRECT);
		}
		return (CORRECT);
	}
	return (INCORRECT);
}
