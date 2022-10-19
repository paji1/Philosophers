/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:43:12 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/19 20:11:23 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	print_states(t_philo *philo, int state)
{
	if (check_pass_time(philo))
		return (1);
	if (state == THINKING && !philo->vars->is_died)
		printf("%ld %d is thinking\n", get_time(philo), philo->id);
	else if (state == SLEPPING && !philo->vars->is_died)
		printf("%ld %d is sleeping\n", get_time(philo), philo->id);
	else if (state == EATING && !philo->vars->is_died)
		printf("%ld %d is eating \n", get_time(philo), philo->id);
	else if (state == TAKE_LEFT && !philo->vars->is_died)
		printf("%ld %d has taken a left fork\n", get_time(philo), philo->id);
	else if (state == TAKE_RIGHT && !philo->vars->is_died)
		printf("%ld %d has taken a right fork\n", get_time(philo), philo->id);
	return (0);
}
