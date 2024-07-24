/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:17:36 by trgaspar          #+#    #+#             */
/*   Updated: 2024/07/18 17:51:26 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>

typedef struct s_philo
{
	int				id;
	int				meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long long		lasteat;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meal;
	t_philo			*philo;
}					t_data;

int		arg_is_ok(char **argv);
int		ft_atoi(const char *src, int *error);
void	init_data(t_data *data, int argc, char **argv);
void	print_data(t_data *data, int argc);

#endif