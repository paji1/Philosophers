/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:44:32 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/20 17:44:50 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long get_time(t_philo *philo)
{
	long	current; 
	long	eposh;
	
	current = philo->vars->current_time.tv_usec / 1000 + \
		philo->vars->current_time.tv_sec * 1000;
	eposh = philo->vars->eposh.tv_usec / 1000 + \
		philo->vars->eposh.tv_sec * 1000;
	return (current - eposh);
}