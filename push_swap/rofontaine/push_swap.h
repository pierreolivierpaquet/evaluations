/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 07:47:19 by rofontai          #+#    #+#             */
/*   Updated: 2023/03/07 14:06:22 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include "./libft/libft.h"

// STRUCTURE-------------------------------------------------------------------
typedef struct s_lst
{
	int				nombre;
	int				index;
	struct s_lst	*next;
}				t_lst;

typedef struct s_stack
{
	t_lst	*a;
	t_lst	*b;
	int		size_a;
	int		size_b;
	int		med_a;
	int		med_b;

}				t_stack;

// ERROR-----------------------------------------------------------------------

void	f_free_list(t_lst **list);
void	f_free_stack(t_stack **pile);
void	f_error(char *str, t_stack **pile, char **tab);

// UTILS-----------------------------------------------------------------------

t_stack	*f_init(void);
t_lst	*f_search_top_index(t_lst *pile);
void	f_addfront_node(t_lst **lst, t_lst *new);
int		f_nombre_mouv(t_lst *list);
int		f_number(char *str, t_stack *pile, char **tab);

// PARSING---------------------------------------------------------------------

t_stack	*f_pars(int argc, char **argv);
void	f_check_double(t_stack *pile, t_lst *node);
void	f_index(t_stack *pile);
void	add_list(char **str, t_stack *pile, int i);
void	add_list_split(char **str, t_stack *pile, int i);

// LINK_LIST-------------------------------------------------------------------

t_lst	*f_new_node(int content, t_stack *pile);
t_lst	*f_last_node(t_lst *list);
void	f_addback_node(t_lst **list, t_lst *new);
t_lst	*f_search_top(t_lst *pile);
t_lst	*f_be_last_node(t_lst *list);

//SORT-------------------------------------------------------------------------

int		f_check_sort(t_lst *list);
void	f_sort(t_stack *pile);
void	f_algo_3(t_stack *pile);

//MOUVE------------------------------------------------------------------------

void	f_push_a(t_stack *pile);
void	f_push_b(t_stack *pile);
void	f_rotate_a(t_stack *pile);
void	f_rotate_b(t_stack *pile);

//MOUVE1-----------------------------------------------------------------------

void	f_swap_a(t_stack *pile);
void	f_swap_b(t_stack *pile);
void	f_reverse_a(t_stack *pile);
void	f_reverse_b(t_stack *pile);

//MOUVE2-----------------------------------------------------------------------

void	f_swap_ab(t_stack *pile);
void	f_reverse_ab(t_stack *pile);
void	f_rotate_ab(t_stack *pile);

//ALGO_BIG---------------------------------------------------------------------

void	f_algo_big(t_stack *pile);
void	transfert_pile_b(t_stack *pile, int i, int div);

#endif
