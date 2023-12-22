/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:21:34 by meltremb          #+#    #+#             */
/*   Updated: 2022/04/05 11:15:28 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* This function basically puts some bytes to zero. you're gonna use it in 
 * calloc unless you're a BIG NERD who does it manually. so you know just a lil
 * counter starting at n and then going -- until it reaches 0 ig all while
 * setting the bites to 0. */

#include"libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*clean;

	clean = s;
	while (n--)
		*clean++ = 0;
}
