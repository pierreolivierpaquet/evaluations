/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorisse <mmorisse@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:16:00 by mmorisse          #+#    #+#             */
/*   Updated: 2023/10/24 13:03:53 by mmorisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (write(fd, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}
