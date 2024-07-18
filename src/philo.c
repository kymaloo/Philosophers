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

unsigned int	ft_atoi(const char *src, int *error)
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
