/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:13:43 by trgaspar          #+#    #+#             */
/*   Updated: 2024/09/24 13:35:06 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_lstclear(t_philo **philo)
{
	t_philo	*tmp;
	t_philo	*tmp2;

	if (!philo)
		return ;
	tmp = *philo;
	while (tmp)
	{
		tmp2 = tmp->next;
		if (philo)
			free(tmp);
		tmp = tmp2;
	}
	*philo = NULL;
}

void	ft_print_all_lst(t_philo *philo)
{
	t_philo	*cursor;

	cursor = philo;
	while (cursor)
	{
		printf("print : %lu\n", cursor->id);
		cursor = cursor->next;
	}
	cursor = ft_lstlast(philo);
}

void	ft_delete_node(t_philo **philo)
{
	t_philo	*tmp;

	if (*philo != NULL)
	{
		tmp = *philo;
		*philo = (*philo)->next;
		free(tmp);
		return ;
	}
}
