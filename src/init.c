/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:51:24 by trgaspar          #+#    #+#             */
/*   Updated: 2024/07/25 15:33:36 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_is_ok(char **argv)
{
	int				i;
	unsigned int	result;
	int				error;

	i = 1;
	result = 0;
	error = 0;
	while (argv[i])
	{
		result = ft_atoi(argv[i], &error);
		if (error == 1 || result < 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *src, int *error)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (src[i] == 32 || (src[i] >= 9 && src[i] <= 13))
		i++;
	if ((src[i] == '-') || (src[i] == '+'))
	{
		if (src[i] == '-')
			*error = 1;
		i++;
	}
	while (src[i] >= '0' && src[i] <= '9')
	{
		nb = (nb * 10) + (src[i] - '0');
		i++;
	}
	if ((nb < 1) || (nb > INT_MAX))
		*error = 1;
	return (nb);
}

void	init_master(t_master *master, int argc, char **argv)
{
	int	error;
	int	i;

	error = 0;
	i = 0;
	master->nb_philo = ft_atoi(argv[1], &error);
	master->time_to_die = ft_atoi(argv[2], &error);
	master->time_to_eat = ft_atoi(argv[3], &error);
	master->time_to_sleep = ft_atoi(argv[4], &error);
	if (argc == 6)
		master->nb_meal = ft_atoi(argv[5], &error);
	else
		master->nb_meal = -1;
	master->fork_array = malloc(master->nb_philo * sizeof(pthread_mutex_t));
	while (i < master->nb_philo)
	{
		pthread_mutex_init(&master->fork_array[i], NULL);
		i++;
	}
}


void	*routine(t_master *master)
{
	pthread_mutex_lock(master->philo->left_fork);
	pthread_mutex_lock(master->philo->right_fork);
	printf("Philo %d has taken a fork\n");
	printf("Philo %d is eating\n");
	usleep(master->time_to_eat);
	pthread_mutex_unlock(master->philo->left_fork);
	pthread_mutex_unlock(master->philo->right_fork);
	printf("Philo %d is sleeping\n");
	usleep(master->time_to_sleep);
	printf("Philo %d is thinking\n");
}
