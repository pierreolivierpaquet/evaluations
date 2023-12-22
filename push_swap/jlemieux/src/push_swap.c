/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:13:30 by jlemieux          #+#    #+#             */
/*   Updated: 2023/03/30 16:46:52 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_env *env)
{
	int	size;

	size = env->size_a;
	if (is_sorted(env))
		return ;
	if (size < 10)
		small_size(env);
	else
		large_size(env);
}
