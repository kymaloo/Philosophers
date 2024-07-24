/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:15:56 by trgaspar          #+#    #+#             */
/*   Updated: 2024/07/18 17:52:05 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	int	status;
	t_data data;

	status = EXIT_FAILURE;
	if (argc < 5 || argc > 6)
	{
		printf("Error: You don't have the right number of arguments\n");
		return (status);
	}
	status = arg_is_ok(argv);
	if (status == EXIT_FAILURE)
	{
		printf("Error: Your arguments are not valid\n");
		return (status);
	}
	memset(&data, 0, sizeof(data));
	init_data(&data, argc, argv);
	print_data(&data, argc);
	return (0);
}

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

void	init_data(t_data *data, int argc, char **argv)
{
	int	error;

	error = 0;
	data->nb_philo = ft_atoi(argv[1], &error);
	data->time_to_die = ft_atoi(argv[2], &error);
	data->time_to_eat = ft_atoi(argv[3], &error);
	data->time_to_sleep = ft_atoi(argv[4], &error);
	if (argc == 6)
		data->nb_meal = ft_atoi(argv[5], &error);
	else
		data->nb_meal = -1;
}

void	print_data(t_data *data, int argc)
{
	printf("Le nombre de philo : %d\nLe temps pour mourir : %d\nLe temps pour manger : %d\nLe temps pour dormir : %d\n", data->nb_philo, data->time_to_die, data->time_to_eat, data->time_to_sleep);
	if (argc == 6)
		printf("Le nombre de repas est : %d\n", data->nb_meal);
}