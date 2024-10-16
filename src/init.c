/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:46:45 by trgaspar          #+#    #+#             */
/*   Updated: 2024/10/16 03:02:32 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

void	init_data(t_master *master, int argc, char **argv)
{
	int	error;

	error = 0;
	master->nb_philo = ft_atoi(argv[1], &error);
	master->time_to_die = ft_atoi(argv[2], &error);
	master->time_to_eat = ft_atoi(argv[3], &error);
	master->time_to_sleep = ft_atoi(argv[4], &error);
	if (argc == 6)
		master->nb_meal = ft_atoi(argv[5], &error);
	else
		master->nb_meal = -1;
	master->iterating = true;
	master->start_time = 0;
	pthread_mutex_init(&master->get_value, NULL);
	pthread_mutex_init(&master->update_value, NULL);
	pthread_mutex_init(&master->writting, NULL);
}

int	init_malloc(t_master *master)
{
	master->philo = malloc(sizeof(t_philo) * master->nb_philo);
	if (!master->philo)
		return (2);
	master->fork = malloc(sizeof(pthread_mutex_t) * master->nb_philo);
	if (!master->fork)
	{
		free(master->philo);
		return (2);
	}
	master->philo_ths = malloc(sizeof(pthread_t) * master->nb_philo);
	if (!master->philo_ths)
	{
		free(master->philo);
		free(master->fork);
		return (2);
	}
	return (0);
}

void	init_philo(t_master *master)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = master->philo;
	while (++i < master->nb_philo)
	{
		philo[i].master = master;
		philo[i].id = i + 1;
		philo[i].meal = 0;
		update_lasteat(&philo[i]);
	}
}

void	init_fork(t_master *master)
{
	int		i;
	t_philo	*philo;

	philo = master->philo;
	i = -1;
	while (++i < master->nb_philo)
		pthread_mutex_init(&master->fork[i], NULL);
	i = 0;
	philo[i].left_fork = &master->fork[i];
	philo[i].right_fork = &master->fork[master->nb_philo - 1];
	while (++i < master->nb_philo)
	{
		philo[i].left_fork = &master->fork[i];
		philo[i].right_fork = &master->fork[i - 1];
	}
}
