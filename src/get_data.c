/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:46:07 by trgaspar          #+#    #+#             */
/*   Updated: 2024/10/16 02:54:02 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_data_nbphilo(t_master *master)
{
	int	data_nbphilo;

	pthread_mutex_lock(&master->get_value);
	data_nbphilo = master->nb_philo;
	pthread_mutex_unlock(&master->get_value);
	return (data_nbphilo);
}

int	get_data_timedie(t_master *master)
{
	int	data_timedie;

	pthread_mutex_lock(&master->get_value);
	data_timedie = master->time_to_die;
	pthread_mutex_unlock(&master->get_value);
	return (data_timedie);
}

int	get_data_timeeat(t_master *master)
{
	int	data_timeeat;

	pthread_mutex_lock(&master->get_value);
	data_timeeat = master->time_to_eat;
	pthread_mutex_unlock(&master->get_value);
	return (data_timeeat);
}

int	get_data_timesleep(t_master *master)
{
	int	data_timesleep;

	pthread_mutex_lock(&master->get_value);
	data_timesleep = master->time_to_sleep;
	pthread_mutex_unlock(&master->get_value);
	return (data_timesleep);
}

int	get_data_nbmeal(t_master *master)
{
	int	data_nbmeal;

	pthread_mutex_lock(&master->get_value);
	data_nbmeal = master->nb_meal;
	pthread_mutex_unlock(&master->get_value);
	return (data_nbmeal);
}
