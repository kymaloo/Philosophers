/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:47:02 by trgaspar          #+#    #+#             */
/*   Updated: 2024/10/17 15:11:25 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	int	status;

	status = EXIT_FAILURE;
	if (argc < 5 || argc > 6)
	{
		printf(NOT_ARGS);
		return (status);
	}
	status = arg_is_ok(argv);
	if (status == EXIT_FAILURE)
	{
		printf("Error: Your arguments are not valid\n");
		return (status);
	}
	philo(argc, argv);
	return (0);
}

int	philo(int argc, char **argv)
{
	t_master	master;

	init_data(&master, argc, argv);
	if (init_malloc(&master))
		return (1);
	init_philo(&master);
	init_fork(&master);
	thread_routine(&master);
	join_threads(&master);
	free_data(&master);
	return (0);
}

int	join_threads(t_master *master)
{
	int	i;
	int	nb_philos;

	nb_philos = get_data_nbphilo(master);
	i = -1;
	if (pthread_join(master->monit_all_alive, NULL))
		return (1);
	while (++i < nb_philos)
	{
		if (pthread_join(master->philo_ths[i], NULL))
			return (1);
	}
	return (0);
}

void	free_data(t_master *master)
{
	int	i;
	int	nb_philos;

	nb_philos = get_data_nbphilo(master);
	i = -1;
	while (++i < nb_philos)
		pthread_mutex_destroy(&master->fork[i]);
	pthread_mutex_destroy(&master->get_value);
	pthread_mutex_destroy(&master->update_value);
	pthread_mutex_destroy(&master->writing);
	free(master->philo_ths);
	free(master->philo);
	free(master->fork);
}
