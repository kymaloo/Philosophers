/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:46:22 by trgaspar          #+#    #+#             */
/*   Updated: 2024/10/16 02:54:28 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	get_data_iter(t_master *master)
{
	bool	data_iter;

	pthread_mutex_lock(&master->get_value);
	data_iter = master->iterating;
	pthread_mutex_unlock(&master->get_value);
	return (data_iter);
}
