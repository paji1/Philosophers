/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behaviors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:19:31 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/22 17:02:27 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int thinking(t_philo *philo)
{
	if (philo->state == THINKING)
	{
		if (print_states(philo, THINKING))
			return (1);
	}
	return (0);
}

int sleeping(t_philo *philo)
{
	if (philo->state == SLEPPING)
	{
		if (print_states(philo, SLEPPING))
			return (1);
		ft_usleep(philo->vars->table->time_to_sleep * 1000, philo);
		philo->state = THINKING;
		// return (1);
	}
	return 0;
}

int eating(t_philo *philo)
{
	if (philo->state == EATING)
	{
		philo->last_eat = get_time(philo);
		if (print_states(philo, EATING))
			return (1);
		ft_usleep(philo->vars->table->time_to_eat * 1000, philo);
	}
	return 0;
}

int do_until
	(int (*thinking)(t_philo *), int (*sleeping)(t_philo *)\
		, int (*eating)(t_philo *), t_philo *philo)
{
	int	i;

	i = 0;
	while (!philo->vars->is_died)
	{
		take_forks(philo, &i);
		if ((*eating)(philo))
			return (1);
		realese_forks(philo);
		if ((*sleeping)(philo))
			return (1);
		if ((*thinking)(philo))
			return (1);
	}
	return (0);
}