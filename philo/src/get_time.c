/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:44:32 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/22 21:53:21 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long get_time(t_philo *philo)
{
	t_timeval	current_time;
	long	eposh;
	long	current; 

	gettimeofday(&current_time, NULL);
	current = current_time.tv_usec / 1000 + \
		current_time.tv_sec * 1000;
	eposh = philo->vars->eposh.tv_usec / 1000 + \
		philo->vars->eposh.tv_sec * 1000;
	return (current - eposh);
}