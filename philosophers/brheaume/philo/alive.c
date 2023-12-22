/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alive.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:04:10 by brheaume          #+#    #+#             */
/*   Updated: 2023/08/18 14:47:48 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_phi_eat(t_phi *p)
{
	usleep(150);
	while (!ft_fetch_key(p) || p->last_meal <= ft_get_time())
	{
		if (p->last_meal <= ft_get_time())
		{
			ft_samael(p);
			return ;
		}
		if (ft_azrael(p))
			break ;
		usleep(100);
	}
	pthread_mutex_lock(&p->left->mutex);
	ft_print(p, "\x1b[33mhas taken a fork\x1b[37m");
	pthread_mutex_lock(&p->right->mutex);
	ft_print(p, "\x1b[33mhas taken a fork\x1b[37m");
	ft_print(p, "\x1b[35mis eating\x1b[37m");
	p->last_meal = ft_get_time() + p->data->info.time_death;
	ft_slumber(p, p->data->info.time_eat);
	pthread_mutex_unlock(&p->left->mutex);
	pthread_mutex_unlock(&p->right->mutex);
	pthread_mutex_lock(&p->data->key_seeker);
	p->left->lock = INCORRECT;
	p->right->lock = INCORRECT;
	pthread_mutex_unlock(&p->data->key_seeker);
}

void	*ft_lives(void *arg)
{
	t_phi	*p;

	p = (t_phi *)arg;
	if (p->data->all_you_can_eat && !p->nb_meals)
		return (NULL);
	p->last_meal = ft_get_time() + p->data->info.time_death;
	if (p->id & 1)
		ft_slumber(p, p->data->info.time_eat);
	while (!ft_azrael(p))
	{
		ft_print(p, "\x1b[36mis thinking\x1b[37m");
		if (!ft_azrael(p))
			ft_phi_eat(p);
		if (p->data->all_you_can_eat)
			p->nb_meals--;
		if (!p->nb_meals && p->data->all_you_can_eat)
			return (NULL);
		if (!ft_azrael(p))
			ft_print(p, "\x1b[36mis sleeping\x1b[37m");
		ft_slumber(p, p->data->info.time_sleep);
	}
	return (NULL);
}
