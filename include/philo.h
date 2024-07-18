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

int				arg_is_ok(char **argv);
unsigned int	ft_atoi(const char *src, int *error);

#endif