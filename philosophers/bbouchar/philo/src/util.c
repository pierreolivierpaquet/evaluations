/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouchar <bbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:39:15 by bbouchar          #+#    #+#             */
/*   Updated: 2023/06/28 15:31:38 by bbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	is_negatif;
	int	number;

	if (str == NULL)
		return (0);
	i = 0;
	is_negatif = 1;
	number = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	if (str[i] == '-')
		is_negatif *= -1;
	else if (str[i] == '+')
		is_negatif = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * is_negatif);
}

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (unsigned long)1000) + (time.tv_usec / 1000));
}

void	new_sleep(unsigned long duration)
{
	unsigned long	time_to_stop_waiting;

	time_to_stop_waiting = get_time() + duration;
	while (get_time() < time_to_stop_waiting - 5)
	{
		usleep(1000);
	}
	while (get_time() < time_to_stop_waiting)
	{
	}
}

void	philo_print(char *message, t_philo *philo)
{
	unsigned long	current_time;
	unsigned long	delta_ms;
	unsigned long	start_ms;

	pthread_mutex_lock(&philo->env->end_mut);
	if (philo->env->end_simulation)
	{
		pthread_mutex_unlock(&philo->env->end_mut);
		return ;
	}
	pthread_mutex_lock(&philo->env->writing);
	current_time = get_time();
	start_ms = (philo->env->start_time.tv_sec * 1000)
		+ (philo->env->start_time.tv_usec / 1000);
	delta_ms = current_time - start_ms;
	printf("%ld %i %s\n", delta_ms, philo->pos, message);
	pthread_mutex_unlock(&philo->env->writing);
	pthread_mutex_unlock(&philo->env->end_mut);
}
