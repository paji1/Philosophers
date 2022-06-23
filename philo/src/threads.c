/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:43:29 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/23 01:57:35 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int join_threads(t_vars *vars)
{
	int i;
	
	i = -1;
	while (++i < vars->table->nb_philo)
		pthread_join(vars->threads[i], &vars->data);
	return (0);
}

int detach_threads(t_vars *vars)
{
	int i;
	
	i = -1;
	while (++i < vars->table->nb_philo)
		pthread_detach(vars->threads[i]);
	return (0);
}

int	create_threads(t_vars *vars, int nb)
{
	t_philo	*philo;
	int	 	j;

	j = -1;
	philo = vars->table->head;
	while (++j < nb)
	{
		philo->vars = vars;
		if (pthread_create(&vars->threads[j], NULL, philo_routine, philo))
			return (ft_free(&vars->table), free(vars->threads), 1);
		philo = philo->next;
	}
	return 0;
}