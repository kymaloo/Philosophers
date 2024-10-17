/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:46:00 by trgaspar          #+#    #+#             */
/*   Updated: 2024/10/17 16:14:53 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat_routine(t_philo *philo)
{
	if (philo_died(philo) || !get_data_iter(philo->master))
		return (1);
	if (take_forks(philo) != 0)
		return (1);
	if (philo_died(philo) || !get_data_iter(philo->master))
		return (1);
	philo_writing(philo, "is eating");
	update_nbmeal(philo);
	update_lasteat(philo);
	ft_usleep(get_data_timeeat(philo->master));
	drop_forks(philo);
	return (0);
}

int	take_forks(t_philo *philo)
{
	if (get_data_nbphilo(philo->master) == 1)
	{
		if (philo_died(philo) || !get_data_iter(philo->master))
			return (1);
		pthread_mutex_lock(philo->left_fork);
		philo_writing(philo, "has taken a fork");
		ft_usleep(get_data_timedie(philo->master));
		return (1);
	}
	if (philo_died(philo) || !get_data_iter(philo->master))
		return (1);
	pthread_mutex_lock(philo->left_fork);
	if (philo_died(philo) || !get_data_iter(philo->master))
		return (pthread_mutex_unlock(&(philo->master->writing)), 1);
	philo_writing(philo, "has taken a fork");
	if (philo_died(philo) || !get_data_iter(philo->master))
	{
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	pthread_mutex_lock(philo->right_fork);
	if (!philo_died(philo) && get_data_iter(philo->master))
		philo_writing(philo, "has taken a fork");
	return (0);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
