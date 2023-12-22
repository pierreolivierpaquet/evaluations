/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:14:32 by meltremb          #+#    #+#             */
/*   Updated: 2023/04/27 11:06:53 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../reworked-libft/libft.h"
# include "../dbl_push_swap/include/dbl_extension_libft.h"

typedef struct s_data
{
	t_pile	*a;
	t_pile	*b;
	int		range;
}			t_data;

void	init_piles(t_data *d);
int		make_pile(t_data *d, int argc, char **argv);
void	swap(t_data *d, char type);
void	push(t_data *d, char type);
void	rotate(t_data *d, t_pile *any, char type);
void	reverse_rotate(t_data *d, t_pile *any, char type);
void	rotate_until(t_data *d, t_pile *any, char type, int count);
int		check_doubles(t_pile *any);
int		too_long(char *str);
int		is_sorted(t_data *d);
int		root(int size);
int		smallest_range(int prev, int new);
void	push_back(t_data *d);
int		counter(t_pile *any, int value);
int		look_for_range(t_data *d, int min, int max, int i);
void	quick_sort(t_data *d);
void	three_sort(t_data *d);
int		smollest(t_pile *any);

#endif