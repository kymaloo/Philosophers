/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:17:36 by trgaspar          #+#    #+#             */
/*   Updated: 2024/07/25 14:28:27 by trgaspar         ###   ########.fr       */
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
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_philo;

typedef struct s_master
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meal;
	t_philo			*philo;
	pthread_mutex_t	*fork_array;
}						t_master;

int		arg_is_ok(char **argv);
int		ft_atoi(const char *src, int *error);
int		ft_strlen(char *str);
void	init_master(t_master *master, int argc, char **argv);
void	print_master(t_master *master, int argc);
void	ft_putstr_fd(char *s, int fd);


#endif