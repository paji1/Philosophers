/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:32:14 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/22 22:00:32 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


long get_times(t_philo *philo)
{
	t_timeval time;
	long	current; 
	long	eposh;

	time.tv_usec = 0;
	time.tv_sec = 0;
	gettimeofday(&time, NULL);
	current = time.tv_usec + time.tv_sec * 1000 * 1000;
	eposh = philo->vars->eposh.tv_usec + philo->vars->eposh.tv_sec * 1000 * 1000;
	return (current - eposh);
}

void ft_usleep(long time, t_philo *philo)
{
	long init;

	init = get_times(philo);
	usleep(time * 0.9);
	while((get_times(philo)) - init < time)
		usleep(50);
}