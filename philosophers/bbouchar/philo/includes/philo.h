/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouchar <BrunoPierreBouchard@hotmail.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:36:37 by bbouchar          #+#    #+#             */
/*   Updated: 2023/07/03 11:18:45 by bbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include "stdbool.h"
# include "limits.h"

# define LEFT 1
# define RIGHT 0

// variables communes
typedef struct s_env
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	pthread_mutex_t	writing;
	pthread_mutex_t	*forks;
	pthread_mutex_t	end_mut;
	pthread_mutex_t	ate_mut;
	struct timeval	start_time;
	bool			end_simulation;
}t_env;

// represente un philo
// hand = 0 (left)
// hand = 1 (right)
typedef struct s_philo
{
	pthread_t		thread_id;
	int				pos;
	int				ate_time;
	struct timeval	last_ate;
	t_env			*env;
	int				r_fork;
	int				l_fork;
}t_philo;

int				ft_atoi(const char *str);
unsigned long	get_time(void);
void			new_sleep(unsigned long duration);
void			*philo_routine(void *args);
bool			init_philos(t_philo **philos, t_env *env);
void			monitor_philos(t_philo **philos, t_env *env);
void			philo_print(char *message, t_philo *philo);
bool			check_num(char *str);

#endif