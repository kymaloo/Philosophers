/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:46:33 by trgaspar          #+#    #+#             */
/*   Updated: 2024/10/16 02:54:34 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_philo_lasteat(t_philo *philo)
{
	long long	lasteat;

	pthread_mutex_lock(&philo->master->get_value);
	lasteat = philo->lasteat;
	pthread_mutex_unlock(&philo->master->get_value);
	return (lasteat);
}
