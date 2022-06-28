/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:43:12 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/28 15:18:32 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int print_states(t_philo *philo, int state)
{
	sem_wait(philo->vars->sem_deat);
	if (state == THINKING)
		printf("%ld %d is thinking\n" , get_time(philo), philo->id);
	else if (state == SLEPPING )
		printf("%ld %d is sleeping\n", get_time(philo), philo->id);
	else if (state == EATING )
		printf("%ld %d is eating \n", get_time(philo), philo->id);
	else if (state == TAKE_LEFT)
		printf("%ld %d has taken a left fork\n", get_time(philo), philo->id);
	else if (state == TAKE_RIGHT)
		printf("%ld %d has taken a right fork\n", get_time(philo), philo->id);
	sem_post(philo->vars->sem_deat);
	return (0);
}