/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:10:37 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/24 23:09:42 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int create_table_ofthreads(t_vars *vars)
{
	vars->threads = malloc(vars->table->nb_philo * sizeof(pthread_t));
	if (!vars->threads)
		return (1);
	return (0);
}

static int init_philo_to_table(t_vars *vars, int nb)
{
	int	i;

	i = -1;
	while (++i < nb)
		if (!add_first(vars->table, add_new_philo(nb)))
			return (ft_free(&vars->table), 1);
	return (0);
}

static void init_times(t_vars *vars, int argc, char **argv)
{
	vars->table->time_to_die = ft_atoi(argv[2]);
	vars->table->time_to_eat = ft_atoi(argv[3]);
	vars->table->time_to_sleep = ft_atoi(argv[4]);
	vars->is_died = 0;
	vars->data = (void *)"";
	if (argc == 6)
		vars->table->must_to_eat = ft_atoi(argv[5]);
}

int	init(t_vars *vars, int argc, char **argv)
{
	int	nb;

	nb = atoi(argv[1]);
	if (!nb || (argc == 6 && !atoi(argv[5])))
		return (1);
	vars->table = NULL;
	if (!init_table(&vars->table, nb))
		return (ft_free(&vars->table), 1);
	init_times(vars, argc, argv);
	if (init_philo_to_table(vars, nb))
		return (1);
	if (create_table_ofthreads(vars))
		return (ft_free(&vars->table), 1);
	if (init_mutexes(vars))
		return (ft_free(&vars->table), 1);	
	gettimeofday(&vars->eposh, NULL);
	if (create_threads(vars, nb))
		return (1);
	return (0);
}