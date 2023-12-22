/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:17:05 by yothmani          #+#    #+#             */
/*   Updated: 2023/09/04 16:44:02 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

void	error_42(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	check_flag(int flag)
{
	if (flag == 0)
	{
		error_42();
	}
}

static int	check_sign(char **str, int i, int *j)
{
	while (*str[i] == 32 || (*str[i] >= 9 && *str[i] <= 13))
		i++;
	if (*str[i] == '+' || *str[i] == '-')
	{
		if (*str[i] == '-')
			*j = -1;
		i++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	num;
	int	flag;

	flag = 0;
	i = 0;
	sign = 1;
	num = 0;
	i = check_sign(&str, i, &sign);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		flag = 1;
		num = num * 10 + sign * (str[i] - 48);
		i++;
		if ((sign == 1 && num < 0) || (sign == -1 && num > 0))
			error_42();
	}
	if (str[i])
		error_42();
	check_flag(flag);
	return (num);
}
