/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:25:43 by meltremb          #+#    #+#             */
/*   Updated: 2022/05/24 15:49:06 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	printd(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		prints("-2");
		nb = (nb + 2000000000) * -1;
		len = len + 2;
	}
	if (nb < 0)
	{
		printc('-');
		nb = nb * -1;
		len++;
	}
	if (nb > 9)
		len = len + printd(nb / 10);
	printc(nb % 10 + 48);
	return (++len);
}

int	printu(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 9)
		len = len + printu(nb / 10);
	printc(nb % 10 + 48);
	return (++len);
}

int	printx(char c, unsigned int nb)
{
	char	*basemin;
	char	*basemaj;
	int		len;

	basemin = "0123456789abcdef";
	basemaj = "0123456789ABCDEF";
	len = 0;
	if (nb >= 16)
		len = len + printx(c, nb / 16);
	if (c == 'x')
		nb = basemin[nb % 16];
	else
		nb = basemaj[nb % 16];
	write (1, &nb, 1);
	return (++len);
}

int	printp(unsigned long long nb)
{
	char			*base;
	unsigned long	len;

	base = "0123456789abcdef";
	len = 0;
	if (nb >= 16)
		len = printp(nb / 16);
	if (len == 0)
		prints("0x");
	nb = base[nb % 16];
	write (1, &nb, 1);
	return (++len);
}
