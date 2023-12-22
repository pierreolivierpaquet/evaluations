/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:42:02 by meltremb          #+#    #+#             */
/*   Updated: 2022/04/05 14:01:21 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_baseconv(int n, int base);

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	const char	*digits = "0123456789";

	len = ft_baseconv(n, 10);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = 0;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n)
	{
		if (n > 0)
			str[--len] = digits[n % 10];
		else
			str[--len] = digits[n % 10 * -1];
		n = n / 10;
	}
	return (str);
}

int	ft_baseconv(int n, int base)
{
	int	i;

	i = 0;
	if (n <= 0)
		++i;
	while (n && ++i)
		n = n / base;
	return (i);
}
