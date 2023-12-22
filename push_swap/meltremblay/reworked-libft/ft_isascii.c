/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:20:17 by meltremb          #+#    #+#             */
/*   Updated: 2022/04/05 11:04:36 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* That one tells you if a character is in the ascii table. what does the 0177
 * means, you ask? I don't fucking know either, I answer. I guess it's the
 * last character but who knows. Some other guy was like "yeah you should finish
 * with 0177" and i just did it and it worked. I didn't look further. */

#include"libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 0177)
		return (1);
	return (0);
}
