/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:32:14 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/23 15:00:39 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


void ft_usleep(long time, t_philo *philo)
{
	long init;

	init = get_time(philo);
	usleep(time * 0.95);
	while((get_time(philo)) - init < time / 1000)
		usleep(85);
}