/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouchar <BrunoPierreBouchard@hotmail.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:27:39 by bbouchar          #+#    #+#             */
/*   Updated: 2023/07/03 11:36:06 by bbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	start_threads(t_philo **philos, t_env *env)
{
	int	i;
	int	return_value;

	i = 0;
	while (i < env->nb_philo)
	{
		return_value = pthread_create(&philos[i]->thread_id,
				NULL, philo_routine, philos[i]);
		if (return_value != 0)
			return (EXIT_FAILURE);
		i ++;
	}
	return (EXIT_SUCCESS);
}

static void	terminate(t_philo **philos, t_env *env, bool exit_code, char *msg)
{
	int	i;

	pthread_mutex_destroy(&env->ate_mut);
	pthread_mutex_destroy(&env->end_mut);
	pthread_mutex_destroy(&env->writing);
	i = 0;
	while (i < env->nb_philo)
	{
		if (env->forks && &env->forks[i] != NULL)
			pthread_mutex_destroy(&env->forks[i]);
		if (philos && philos[i])
			free(philos[i]);
		i++;
	}
	if (philos)
		free(philos);
	if (env->forks)
		free(env->forks);
	if (msg)
		printf("%s\n", msg);
	exit(exit_code);
}

static void	init_forks(t_philo **philos, t_env *env)
{
	int	i;

	i = 0;
	env->forks = malloc(sizeof(pthread_mutex_t) * env->nb_philo);
	if (!env->forks)
		terminate(philos, env, EXIT_FAILURE, "Malloc Error");
	while (i < env->nb_philo)
	{
		pthread_mutex_init(&env->forks[i], NULL);
		i++;
	}
}

static bool	init_env(t_philo ***philos, t_env *env, char **argv, int argc)
{
	int	i;

	i = 0;
	*philos = NULL;
	env->forks = NULL;
	pthread_mutex_init(&env->writing, NULL);
	pthread_mutex_init(&env->end_mut, NULL);
	pthread_mutex_init(&env->ate_mut, NULL);
	if (argc < 5 || argc > 6)
		return (false);
	while (i++ < argc - 1)
		if (check_num (argv[i]) == false)
			return (false);
	env->nb_philo = ft_atoi(argv[1]);
	env->time_to_die = ft_atoi(argv[2]);
	env->time_to_eat = ft_atoi(argv[3]);
	env->time_to_sleep = ft_atoi(argv[4]);
	env->nb_must_eat = ft_atoi(argv[5]);
	env->end_simulation = false;
	gettimeofday(&env->start_time, NULL);
	if (env->nb_philo > 0 && env->nb_philo <= 200
		&& env->time_to_die >= 60 && env->time_to_eat >= 60
		&& env->time_to_sleep >= 60 && env->nb_must_eat >= 0)
		return (true);
	return (false);
}

int	main(int argc, char **argv)
{
	t_philo	**philos;
	t_env	env;
	int		i;

	if (!init_env(&philos, &env, argv, argc))
		terminate(philos, &env, EXIT_FAILURE, "Invalid arguments");
	philos = malloc(sizeof(t_philo *) * env.nb_philo);
	if (!philos)
		terminate(philos, &env, EXIT_FAILURE, "Malloc Error");
	init_forks(philos, &env);
	if (init_philos(philos, &env) == EXIT_FAILURE)
		terminate(philos, &env, EXIT_FAILURE, "Malloc Error");
	if (start_threads(philos, &env) == EXIT_FAILURE)
		terminate(philos, &env, EXIT_FAILURE, "Failed to start Thread");
	monitor_philos(philos, &env);
	i = 0;
	while (i < env.nb_philo)
	{
		pthread_join(philos[i]->thread_id, NULL);
		i++;
	}
	terminate(philos, &env, EXIT_SUCCESS, NULL);
	return (EXIT_SUCCESS);
}
