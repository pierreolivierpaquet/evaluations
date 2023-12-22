/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:58:51 by meltremb          #+#    #+#             */
/*   Updated: 2022/04/05 11:05:35 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* that one is for printable characters in the ascii table. that's it folks. */

#include"libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
