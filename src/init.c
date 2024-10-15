/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:51:24 by trgaspar          #+#    #+#             */
/*   Updated: 2024/09/25 11:59:07 by trgaspar         ###   ########.fr       */
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

unsigned long long	ft_atoi(const char *src, int *error)
{
	unsigned long long	nb;
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
	// ! Check Nombre Float
	master->nb_philo = ft_atoi(argv[1], &error);
	master->time_to_die = ft_atoi(argv[2], &error);
	master->time_to_eat = ft_atoi(argv[3], &error);
	master->time_to_sleep = ft_atoi(argv[4], &error);
	if (argc == 6)
		master->nb_meal = ft_atoi(argv[5], &error);
	else
		master->nb_meal = -1;
}

void	*routine(void *arg)
{
	t_master *master;

	master = (t_master *)arg;
	pthread_mutex_lock(master->philo->left_fork);
	pthread_mutex_lock(master->philo->right_fork);
	printf("Philo %lu has taken a fork\n", master->philo->id);
	printf("Philo %lu is eating\n", master->philo->id);
	usleep(master->time_to_eat);
	pthread_mutex_unlock(master->philo->left_fork);
	pthread_mutex_unlock(master->philo->right_fork);
	printf("Philo %lu is sleeping\n", master->philo->id);
	usleep(master->time_to_sleep);
	printf("Philo %lu is thinking\n", master->philo->id);
	return (NULL);
}

void	create_philo(t_master *master)
{
	int id;
	int error;
	
	id = 0;
	error = 0;
	while (id != master->nb_philo)
	{
		ft_lstadd_back(&master->philo, ft_lstnew(id, &error));
		if (error == -1)
			return ;
		id++;
	}
}

void	assign_fork(t_master *master)
{
	t_philo *cursor;
	t_philo	*tmp;
	int	i;

	i = 2;
	cursor = master->philo;
	tmp = cursor;
	cursor->right_fork = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(cursor->right_fork, NULL);
	cursor->left_fork = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(cursor->left_fork, NULL);
	cursor = cursor->next;
	while (cursor)
	{
		cursor->left_fork = tmp->right_fork;
		if (i == master->nb_philo)
		{
			tmp = master->philo;
			cursor->right_fork = tmp->left_fork;
		}
		else
		{
			cursor->right_fork = malloc(sizeof(pthread_mutex_t));
			pthread_mutex_init(cursor->right_fork, NULL);
		}
		cursor = cursor->next;
		i++;
	}
}
