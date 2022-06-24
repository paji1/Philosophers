/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:25:14 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/22 18:08:41 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void ft_free(t_table **table)
{
	t_philo	*temp;
	int 	i;

	i = -1;
	if (!*table || !(*table)->head)
		return ;
	while (++i < (*table)->nb_philo)
	{
		temp = (*table)->head->next;
		free((*table)->head);
		(*table)->head = temp;
	}
	free(*table);
}

void free_all(t_vars *vars)
{
	// printf("hello\n");
	destroy_mutexs(vars);
	free(vars->threads);
	free(vars->fork);
	ft_free(&vars->table);
	free(vars);
}