/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorisse <mmorisse@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:17:38 by mmorisse          #+#    #+#             */
/*   Updated: 2023/10/24 13:06:53 by mmorisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (c);
	return (0);
}

int	ft_atoi(const char *str)
{
	t_list	ax;

	ft_bzero(&ax, sizeof(t_list));
	ax.f = 1;
	if (!str)
		return ('\0');
	while (*str && ft_isspace(*str))
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			ax.f *= -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		ax.b = ax.a;
		ax.a = ax.a * 10 + ax.f * (*str - 48);
		if (ax.a > ax.b && ax.f < 0)
			return (0);
		if (ax.a < ax.b && ax.f > 0)
			return (-1);
		str++;
	}
	return (ax.a);
}
