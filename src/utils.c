/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:47:28 by trgaspar          #+#    #+#             */
/*   Updated: 2024/10/17 16:03:35 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	gettime(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_usleep(size_t time)
{
	size_t	start;

	start = gettime();
	while ((gettime() - start) < time)
		usleep(500);
}

void	philo_writing(t_philo *philo, char *str)
{
	pthread_mutex_lock(&(philo->master->writing));
	if (philo_died(philo) && ft_strcmp(str, "died"))
	{
		pthread_mutex_unlock(&(philo->master->writing));
		return ;
	}
	printf("%lli %d ", (gettime() - philo->master->start_time), philo->id);
	printf("%s\n", str);
	pthread_mutex_unlock(&(philo->master->writing));
}

bool	philo_died(t_philo *philo)
{
	bool		result;
	t_master	*master;

	master = philo->master;
	result = false;
	if (gettime() - get_philo_lasteat(philo) > get_data_timedie(master))
		result = true;
	return (result);
}

void	stop_philo(t_master *master)
{
	int		i;
	int		nb_philo;

	nb_philo = get_data_nbphilo(master);
	i = -1;
	while (++i < nb_philo)
		update_iter(master, false);
}
