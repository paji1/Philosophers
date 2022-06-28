/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:41:09 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/28 19:35:06 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*check_die(void *phil)
{
	t_philo *philo;

	philo = (t_philo *)phil;
	while (1)
	{
		sem_wait(philo->vars->sem_deat);
		finish_eating(philo);
		if (get_time(philo) - philo->last_eat > philo->vars->time_to_die)
		{
			printf("%ld %d is died\n", get_time(philo) , philo->id);
			exit(EXIT_SUCCESS);
		}
		sem_post(philo->vars->sem_deat);
	}
	return (NULL);
}

void	finish_eating(t_philo *philo)
{
	if (philo->vars->must_to_eat && \
	philo->vars->n_num >= philo->vars->must_to_eat)
	{
		sem_post(philo->vars->sem_deat);
		exit(3);
	}
}