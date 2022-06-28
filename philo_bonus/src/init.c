/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:10:37 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/28 15:46:25 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"




static void init_times(t_vars *vars, int argc, char **argv)
{
	vars->time_to_die = ft_atoi(argv[2]);
	vars->time_to_eat = ft_atoi(argv[3]);
	vars->time_to_sleep = ft_atoi(argv[4]);
	vars->nb_philo =  ft_atoi(argv[1]);
	vars->n_num = 0;
	if (argc == 6)
		vars->must_to_eat = ft_atoi(argv[5]);
}

int	init(t_vars *vars, int argc, char **argv)
{
	int	nb;

	nb = atoi(argv[1]);
	if (!nb || (argc == 6 && !atoi(argv[5])))
		return (1);
	init_times(vars, argc, argv);
	gettimeofday(&vars->eposh, NULL);
	vars->pids = malloc(sizeof(pid_t) * vars->nb_philo);
	if (vars->pids == NULL)
		return (1);
	sem_unlink("semaphore");
	sem_unlink("sem_death");
	vars->semaphore = sem_open("semaphore", O_CREAT, 0777, vars->nb_philo);
	vars->sem_deat = sem_open("sem_death", O_CREAT, 0777, 1);
	return (0);
}