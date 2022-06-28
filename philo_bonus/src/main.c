/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:17:26 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/28 01:06:29 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/philo.h"

void	*philo_routine(void *philo)
{
	if (do_until(thinking, sleeping, eating, (t_philo *)philo))
		return NULL;
	return philo;
}




int main(int argc, char **argv)
{
	t_vars vars;

	if (parse(argc, argv))
		return (1);
	if (init(&vars, argc, argv))
		return (1);
	int l = create_process(&vars);
	if (l)
	{
		
	int pid = waitpid(0, NULL, 0);
	if (pid != -1)
	{
		send_kill(vars.pids, vars.nb_philo , pid);	
	}
	}
	return (0);
}
