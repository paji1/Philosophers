/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:41:09 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/23 00:55:37 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_pass_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->vars->fork[philo->vars->table->nb_philo]);
	if (philo->vars->is_died)
	{
		pthread_mutex_unlock(&philo->vars->fork[philo->vars->table->nb_philo]);
		return  1;
	}
	if (get_time(philo) - philo->last_eat > philo->vars->table->time_to_die)
	{
		philo->vars->is_died = 1;
		pthread_mutex_unlock(&philo->vars->fork[philo->vars->table->nb_philo]);
		return (1);
	}
	// printf("hello");
	if (philo->vars->is_died)
	{
		
		pthread_mutex_unlock(&philo->vars->fork[philo->vars->table->nb_philo]);
		return  1;
	}
	pthread_mutex_unlock(&philo->vars->fork[philo->vars->table->nb_philo]);
	return (0);
}