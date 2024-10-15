/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:15:56 by trgaspar          #+#    #+#             */
/*   Updated: 2024/09/25 11:35:32 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	int				status;
	int				error;
	t_master		master;

	error = 0;
	status = EXIT_FAILURE;
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Error: You don't have the right number of arguments\n", 2);
		return (status);
	}
	status = arg_is_ok(argv);
	if (status == EXIT_FAILURE)
	{
		ft_putstr_fd("Error: Your arguments are not valid\n", 2);
		return (status);
	}
	memset(&master, 0, sizeof(master));
	init_master(&master, argc, argv);
	create_philo(&master);
	assign_fork(&master);
	//ft_print_all_lst(master.philo);
	//print_master(&master, argc);
	return (0);
}
