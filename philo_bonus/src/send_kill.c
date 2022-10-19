/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_kill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 23:02:11 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/19 20:40:33 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	send_kill(pid_t *pids, int nb, pid_t pid_rec)
{
	int	i;

	i = -1;
	while (++i < nb)
	{
		if (pids[i] != pid_rec)
			kill(pids[i], SIGKILL);
	}
}
