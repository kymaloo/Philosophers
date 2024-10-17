/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:45:41 by trgaspar          #+#    #+#             */
/*   Updated: 2024/10/17 15:35:59 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define NOT_ARGS "Error: You don't have the right number of arguments\n"

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>

struct				s_master;

typedef struct s_philo
{
	int				id;
	int				meal;
	struct s_master	*master;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long long		lasteat;
}					t_philo;

typedef struct s_master
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meal;
	bool			iterating;
	long long		start_time;
	pthread_mutex_t	get_value;
	pthread_mutex_t	update_value;
	pthread_mutex_t	writing;
	pthread_t		monit_all_alive;
	pthread_t		*philo_ths;
	pthread_mutex_t	*fork;
	t_philo			*philo;
}					t_master;

//MAIN

int					philo(int argc, char **argv);
int					join_threads(t_master *master);
void				free_data(t_master *master);

//INIT

void				init_data(t_master *master, int argc, char **argv);
int					init_malloc(t_master *master);
void				init_philo(t_master *master);
void				init_fork(t_master *master);

//ROUTINE

int					thread_routine(t_master *master);
void				*philo_routine(void *philo);
void				*dead_routine(void *void_master);
int					sleep_routine(t_philo *philo);
int					think_routine(t_philo *philo);

//EAT

int					eat_routine(t_philo *philo);
int					take_forks(t_philo *philo);
void				drop_forks(t_philo *philo);

//LIBFT

unsigned long long	ft_atoi(const char *src, int *error);
int					arg_is_ok(char **argv);
int					ft_strcmp(char *s1, char *s2);

//UTILS

long long			gettime(void);
void				ft_usleep(size_t time);
void				philo_writing(t_philo *philo, char *str);
bool				philo_died(t_philo *philo);
void				stop_philo(t_master *master);

//GET_DATA

int					get_data_nbphilo(t_master *master);
int					get_data_timedie(t_master *master);
int					get_data_timeeat(t_master *master);
int					get_data_timesleep(t_master *master);
int					get_data_nbmeal(t_master *master);

//GET_DATA2

bool				get_data_iter(t_master *master);

//GET_PHILO

long long			get_philo_lasteat(t_philo *philo);

//UPDATE_VALUE

void				update_lasteat(t_philo *philo);
void				update_nbmeal(t_philo *philo);
void				update_iter(t_master *master, bool update);

#endif