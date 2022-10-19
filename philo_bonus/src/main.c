/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:17:26 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/19 20:37:00 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_routine(void *philo)
{
	if (do_until(thinking, sleeping, eating, (t_philo *)philo))
		return (NULL);
	return (philo);
}

int	wait_toeat(int state)
{
	if (state)
	{
		while (waitpid(-1, NULL, 0) != -1)
			;
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	pid_t	pid;
	int		stat_loc;

	if (parse(argc, argv))
		return (1);
	if (init(&vars, argc, argv))
		return (1);
	if (create_process(&vars))
	{
		pid = waitpid(-1, &stat_loc, 0);
		wait_toeat(stat_loc);
		if (pid != -1)
		{
			send_kill(vars.pids, vars.nb_philo, pid);
			sem_close(vars.sem_deat);
			sem_close(vars.semaphore);
		}
	}
	return (0);
}
