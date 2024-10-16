/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:47:22 by trgaspar          #+#    #+#             */
/*   Updated: 2024/10/16 03:11:48 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_lasteat(t_philo *philo)
{
	pthread_mutex_lock(&philo->master->update_value);
	philo->lasteat = gettime();
	pthread_mutex_unlock(&philo->master->update_value);
}

void	update_nbmeal(t_philo *philo)
{
	pthread_mutex_lock(&philo->master->update_value);
	philo->meal++;
	pthread_mutex_unlock(&philo->master->update_value);
}

void	update_iter(t_master *master, bool update)
{
	pthread_mutex_lock(&master->update_value);
	master->iterating = update;
	pthread_mutex_unlock(&master->update_value);
}
