/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouchar <bbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:24:56 by bbouchar          #+#    #+#             */
/*   Updated: 2023/06/28 15:38:49 by bbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_philos(t_philo **philos, t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_philo)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
			return (EXIT_FAILURE);
		philos[i]->ate_time = 0;
		philos[i]->pos = i + 1;
		philos[i]->thread_id = 0;
		philos[i]->env = env;
		philos[i]->r_fork = i;
		philos[i]->l_fork = (i + 1) % env->nb_philo;
		philos[i]->last_ate = env->start_time;
		i++;
	}
	return (EXIT_SUCCESS);
}

static bool	philo_eat(void *args)
{
	t_philo	*philo;

	philo = (t_philo *) args;
	philo_print("is eating", args);
	pthread_mutex_lock(&philo->env->ate_mut);
	gettimeofday(&philo->last_ate, NULL);
	pthread_mutex_unlock(&philo->env->ate_mut);
	new_sleep(philo->env->time_to_eat);
	pthread_mutex_lock(&philo->env->ate_mut);
	philo->ate_time ++;
	pthread_mutex_unlock(&philo->env->ate_mut);
	if ((philo->env->nb_must_eat != 0)
		&& philo->ate_time >= philo->env->nb_must_eat)
		return (true);
	return (false);
}

static void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->forks[philo->r_fork]);
	philo_print("has taken a fork", philo);
	pthread_mutex_lock(&philo->env->forks[philo->l_fork]);
	philo_print("has taken a fork", philo);
}

static int	philo_routine_2(t_philo *philo, void *args)
{
	if (philo->l_fork == philo->r_fork)
		return (0);
	take_fork(philo);
	if (philo_eat(args))
	{
		pthread_mutex_unlock(&philo->env->forks[philo->l_fork]);
		pthread_mutex_unlock(&philo->env->forks[philo->r_fork]);
		return (1);
	}
	pthread_mutex_unlock(&philo->env->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->env->forks[philo->r_fork]);
	philo_print("is sleeping", philo);
	new_sleep(philo->env->time_to_sleep);
	philo_print("is thinking", philo);
	return (0);
}

void	*philo_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->pos % 2)
		usleep(15000);
	while (true)
	{
		pthread_mutex_lock(&philo->env->end_mut);
		if (philo->env->end_simulation)
		{
			pthread_mutex_unlock(&philo->env->end_mut);
			break ;
		}
		pthread_mutex_unlock(&philo->env->end_mut);
		if (philo_routine_2(philo, args) == 1)
			break ;
	}
	return (NULL);
}
