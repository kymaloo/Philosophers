/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:13:00 by trgaspar          #+#    #+#             */
/*   Updated: 2024/09/24 14:59:03 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_lstadd_back(t_philo **philo, t_philo *new)
{
	t_philo	*tmp;

	if (!*philo)
		*philo = new;
	else
	{
		tmp = ft_lstlast(*philo);
		tmp->next = new;
	}
}

int	ft_lstsize(t_philo *philo)
{
	int	i;

	i = 0;
	while (philo)
	{
		philo = philo->next;
		i++;
	}
	return (i);
}

t_philo	*ft_lstlast(t_philo *philo)
{
	int	i;

	i = ft_lstsize(philo);
	while (i-- > 1)
		philo = philo->next;
	return (philo);
}

t_philo	*ft_lstnew(int id, int *error)
{
	t_philo	*philo;
	int		status;

	status = 0;
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	printf("Création du thread pour le philosophe %d\n", id);
	status = pthread_create(&philo->id, NULL, routine, NULL);
	if (status != 0)
		*error = -1;
	philo->id = id;
	philo->next = NULL;
	return (philo);
}
