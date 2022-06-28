/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:46:38 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/28 17:20:13 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	take_forks(t_philo *philo, int *i)
{
	if (!*i && philo->state == THINKING && (philo->id % 2))
	{
		ft_usleep(500, philo);
		if (philo->vars->nb_philo != 1)
			print_states(philo, THINKING);
		*i = 1;
	}
	sem_wait(philo->vars->semaphore);
	if (print_states(philo, TAKE_LEFT))
		return (1);
	sem_wait(philo->vars->semaphore);
	if (print_states(philo, TAKE_RIGHT))
		return (1);
	philo->state = EATING;
	return (0);
}

int	realese_forks(t_philo *philo)
{
	sem_post(philo->vars->semaphore);
	sem_post(philo->vars->semaphore);
	philo->state = SLEPPING;
	return (0);
}
