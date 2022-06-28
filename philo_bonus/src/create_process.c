/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:42:05 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/28 00:48:47 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int create_philo_process(t_vars *vars, int id)
{
	t_philo philo;
	pthread_t thread;

	philo.vars = vars;
	philo.id = id;
	philo.last_eat = get_time(&philo);
	philo.state = THINKING;
	free(vars->pids);
	pthread_create(&thread, NULL, check_die, &philo);
	philo_routine(&philo);
	pthread_join(thread, NULL);
}
int	create_process(t_vars *vars)
{
	pid_t	pid;
	int		i;

	pid = 1;
	i = -1;
	while (++i < vars->nb_philo)
	{
		if (pid)
		{
			pid = fork();
			if (pid != -1 && pid)
				vars->pids[i] = pid;
		}
		if (!pid)
			create_philo_process(vars, i + 1);
	}
	return pid;
}