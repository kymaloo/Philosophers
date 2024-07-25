/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:52:55 by trgaspar          #+#    #+#             */
/*   Updated: 2024/07/25 12:55:37 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_master(t_master *master, int argc)
{
	printf("Le nombre de philo : %d\nLe temps pour mourir : %d\nLe temps pour manger : %d\nLe temps pour dormir : %d\n", master->nb_philo, master->time_to_die, master->time_to_eat, master->time_to_sleep);
	if (argc == 6)
		printf("Le nombre de repas est : %d\n", master->nb_meal);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int ft_strlen(char *str)
{
    int i;
    
    i = 0;
	while (str[i])
		i++;
	return (i);
}
