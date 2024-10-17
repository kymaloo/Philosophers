/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:47:10 by trgaspar          #+#    #+#             */
/*   Updated: 2024/10/17 16:20:16 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thread_routine(t_master *master)
{
	int	i;
	int	nb_of_philos;

	nb_of_philos = get_data_nbphilo(master);
	i = 0;
	master->start_time = gettime();
	while (i < nb_of_philos)
	{
		if (pthread_create(&master->philo_ths[i], NULL,
				&philo_routine, &master->philo[i]))
			return (1);
		i++;
	}
	if (pthread_create(&master->monit_all_alive, NULL,
			&dead_routine, master))
		return (1);
	return (0);
}

void	*philo_routine(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	update_lasteat(philo);
	if (philo->id % 2 == 0)
		usleep(5000);
	while (get_data_iter(philo->master) && !philo_died(philo) \
		&& philo->meal != philo->master->nb_meal)
	{
		if (eat_routine(philo) != 0)
			break ;
		if (philo_died(philo) || !get_data_iter(philo->master))
			break ;
		if (sleep_routine(philo) != 0)
			break ;
		if (philo_died(philo) || !get_data_iter(philo->master))
			break ;
		if (think_routine(philo) != 0)
			break ;
		if (philo_died(philo) || !get_data_iter(philo->master))
			break ;
	}
	return (NULL);
}

void	*dead_routine(void *void_master)
{
	int			i;
	int			nb_philo;
	t_master	*master;
	t_philo		*philo;

	master = (t_master *)void_master;
	philo = master->philo;
	nb_philo = get_data_nbphilo(master);
	i = -1;
	while (++i < nb_philo && get_data_iter(master))
	{
		if (philo->meal == master->nb_meal)
			return (stop_philo(master), NULL);
		if (philo_died(&philo[i]) && get_data_iter(master))
		{
			stop_philo(master);
			philo_writing(&philo[i], "died");
			break ;
		}
		if (i == nb_philo - 1)
			i = -1;
		usleep(1000);
	}
	return (NULL);
}

int	sleep_routine(t_philo *philo)
{
	if (philo_died(philo) || !get_data_iter(philo->master))
		return (1);
	philo_writing(philo, "is sleeping");
	ft_usleep(get_data_timesleep(philo->master));
	return (0);
}

int	think_routine(t_philo *philo)
{
	if (philo_died(philo) || !get_data_iter(philo->master))
		return (1);
	philo_writing(philo, "is thinking");
	return (0);
}
