/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouchar <bbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:24:52 by bbouchar          #+#    #+#             */
/*   Updated: 2023/07/03 12:35:34 by bbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_philo_dead(t_philo *philo)
{
	unsigned long	delta_time;
	unsigned long	last_ate_ms;
	unsigned long	current_ms;

	pthread_mutex_lock(&philo->env->ate_mut);
	if (philo->env->nb_must_eat > 0
		&& philo->ate_time >= philo->env->nb_must_eat)
	{
		pthread_mutex_unlock(&philo->env->ate_mut);
		return (false);
	}
	current_ms = get_time();
	last_ate_ms = (philo->last_ate.tv_sec * 1000)
		+ (philo->last_ate.tv_usec / 1000);
	pthread_mutex_unlock(&philo->env->ate_mut);
	delta_time = current_ms - last_ate_ms;
	if (delta_time >= (unsigned long)philo->env->time_to_die)
		return (true);
	return (false);
}

// check if all philo have eat
static bool	monitor_eat(t_philo **philos, t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_philo)
	{
		pthread_mutex_lock(&env->ate_mut);
		if (philos[i]->ate_time < philos[i]->env->nb_must_eat)
		{
			pthread_mutex_unlock(&env->ate_mut);
			return (false);
		}
		pthread_mutex_unlock(&env->ate_mut);
		i++;
	}
	return (true);
}

static void	print(char *message, t_philo *philo)
{
	unsigned long	current_time;
	unsigned long	delta_ms;
	unsigned long	start_ms;

	pthread_mutex_lock(&philo->env->writing);
	current_time = get_time();
	start_ms = (philo->env->start_time.tv_sec * 1000)
		+ (philo->env->start_time.tv_usec / 1000);
	delta_ms = current_time - start_ms;
	printf("%ld %i %s\n", delta_ms, philo->pos, message);
	pthread_mutex_unlock(&philo->env->writing);
}

static bool	check_eat(t_philo **philos, t_env *env)
{
	pthread_mutex_lock(&env->end_mut);
	if (env->nb_must_eat != 0 && monitor_eat(philos, env))
	{
		env->end_simulation = true;
		printf("%s\n", "All philo have eat !");
		pthread_mutex_unlock(&env->end_mut);
		return (true);
	}
	pthread_mutex_unlock(&env->end_mut);
	return (false);
}

void	monitor_philos(t_philo **philos, t_env *env)
{
	int	i;

	while (true)
	{
		i = 0;
		while (i < env->nb_philo)
		{
			pthread_mutex_lock(&env->end_mut);
			if (check_philo_dead(philos[i]))
			{
				print("died", philos[i]);
				env->end_simulation = true;
				pthread_mutex_unlock(&env->end_mut);
				return ;
			}
			pthread_mutex_unlock(&env->end_mut);
			i++;
		}
		if (check_eat(philos, env))
			return ;
	}
}
