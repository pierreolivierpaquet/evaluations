/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouchar <bbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:15:32 by bbouchar          #+#    #+#             */
/*   Updated: 2023/07/03 12:35:22 by bbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
	{
		return (1);
	}
	return (0);
}

static long	ft_atoi_long(const char *str)
{
	int		i;
	int		is_negatif;
	long	number;

	if (str == NULL)
		return (0);
	i = 0;
	is_negatif = 1;
	number = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	if (str[i] == '-')
		is_negatif *= -1;
	else if (str[i] == '+')
		is_negatif = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * is_negatif);
}

bool	check_num(char *str)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (str[i] != 0)
	{
		if (ft_isdigit(str[i]) == 0 && !(str[i] == '-' && i == 0))
			return (false);
		if (str[i] == '-' && !ft_isdigit(str[i + 1]))
			return (false);
		i++;
	}
	num = ft_atoi_long(str);
	if (num >= INT_MIN && num <= INT_MAX && i <= 11)
		return (true);
	else
		return (false);
	return (true);
}
