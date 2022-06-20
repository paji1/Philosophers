/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:43:12 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/20 17:47:06 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void print_states(t_philo *philo, int state)
{
	gettimeofday(&philo->vars->current_time, NULL);
	if (state == THINKING)
		printf("\n %ld %d is thinking " , get_time(philo), philo->id);
	else if (state == SLEPPING)
		printf("\n %ld %d is sleeping ", get_time(philo), philo->id);
	else if (state == EATING)
		printf("\n %ld %d is eating ", get_time(philo), philo->id);
	else if (state == TAKE_LEFT)
		printf("\n %ld %d has taken a left fork", get_time(philo), philo->id);
	else if (state == TAKE_RIGHT)
		printf("\n %ld %d has taken a right fork", get_time(philo), philo->id);
}