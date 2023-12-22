/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:37:30 by meltremb          #+#    #+#             */
/*   Updated: 2022/04/05 10:58:40 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* If you can't figure out what this function is doing whare are you doing here 
 * it tells you if a character if a fucking letter. you can do that
 * with your little pea brain. something something about ascii tables too*/

#include"libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (c);
	else
		return (0);
}
