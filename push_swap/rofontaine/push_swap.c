/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:14:07 by rofontai          #+#    #+#             */
/*   Updated: 2023/03/07 08:22:05 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*push;

	push = f_pars(argc, argv);
	f_index(push);
	f_sort(push);
	f_free_list (&push->a);
	f_free_list (&push->b);
	f_free_stack (&push);
	return (0);
}
