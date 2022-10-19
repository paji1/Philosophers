/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:46:00 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/19 19:56:33 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_mutexes(t_vars *vars)
{
	int	i;

	i = -1;
	vars->fork = malloc(sizeof(pthread_mutex_t) * (vars->table->nb_philo + 1));
	if (!(vars->fork))
		return (1);
	while (++i < vars->table->nb_philo + 1)
		if (pthread_mutex_init(&vars->fork[i], NULL))
			return (1);
	return (0);
}

void	destroy_mutexs(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->table->nb_philo + 1)
		pthread_mutex_destroy(&vars->fork[i]);
}
