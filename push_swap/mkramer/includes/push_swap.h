/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:12:30 by mkramer           #+#    #+#             */
/*   Updated: 2023/09/19 19:12:30 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_steps
{
	int				count_a;
	int				count_b;
	int				dest_a;
	int				dest_b;
}					t_steps;

typedef struct s_data
{
	int				a[10000];
	int				count_element;
}					t_data;

typedef struct s_stack
{
	int				data;
	int				step;
	int				rotate;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	int				count_a;
	int				count_b;
	int				min;
	int				max;
	int				med;
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

int					ft_only_spaces(const char *str);
int					is_sorted(t_data *new);
void				ft_rrr(t_stacks *s, int i);

int					is_valid(int argc, char **argv);
void				is_num_available(const char *str);
void				is_string_valid(const char *str);
void				is_doubles(t_data *new, t_stacks *stacks);
void				search_doubles(const int *dup, int count);

void				break_2_array(int argc, char **argv, t_data *new);
void				fill_stack(t_data *new, int *buff, int count);

void				init_stack(t_data *new, t_stacks *stacks);
t_stack				*create_stack(const int *buff, int cnt);
void				free_stack(t_stacks *stacks);
void				sort_stack(t_stacks *stacks);
void				to_null(t_stacks *stacks, t_data *new);

void				sort_3(t_stacks *stacks);
void				sort_5(t_stacks *stacks);
int					ft_max(t_stack *s);

void				ft_quick_sort(int *array, int start, int end);
int					breaking(int *array, int start, int end);

void				global_sort(t_stacks *stacks);
void				start_sort(t_stacks *stacks);
void				steps_markup(t_stack *b, int count);
void				min_steps_2_insert(t_stacks *stacks,
						t_steps *steps);
void				rules_perfom(t_stacks *stacks, t_steps *steps);

void				help_find_place(t_stacks *s, t_stack *b,
						int *action, int *buff);
int					find_place(t_stacks *s, t_stack *b,
						t_steps *steps, int min);
int					find_smaller_element(t_stack *a, int buff, int src);
int					count_2_min(t_stack *a, int min);

void				ft_ra(t_stack **a, int i);
void				ft_rb(t_stack **b, int i);
void				ft_rr(t_stacks *s, int i);
void				ft_rra(t_stack **a, int i);
void				ft_rrb(t_stack **b, int i);

void				ft_sa(t_stack *a, int i);
void				ft_sb(t_stack *a, int i);
void				ft_ss(t_stacks *s, int i);
void				ft_pa(t_stacks *s, int i);
void				ft_pb(t_stacks *s, int i);

int					is_stack_sorted(t_stacks *s);
void				read_action(t_stacks *s);
void				actions(char *line, t_stacks *s);

void				free_new(t_data *some);
void				free_stacks(t_stacks *some);

#endif
