/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:46:00 by trgaspar          #+#    #+#             */
/*   Updated: 2024/10/16 02:52:50 by trgaspar         ###   ########.fr       */
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
	printf("iter %d\n", get_data_iter(philo->master));
	philo_writting(philo, "is eating");
	update_lasteat(philo);
	ft_usleep(get_data_timeeat(philo->master));
	update_nbmeal(philo);
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
		philo_writting(philo, "has taken a fork");
		ft_usleep(get_data_timedie(philo->master));
		return (1);
	}
	if (philo_died(philo) || !get_data_iter(philo->master))
		return (1);
	pthread_mutex_lock(philo->left_fork);
	philo_writting(philo, "has taken a fork");
	if (philo_died(philo) || !get_data_iter(philo->master))
	{
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	pthread_mutex_lock(philo->right_fork);
	philo_writting(philo, "has taken a fork");
	return (0);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
