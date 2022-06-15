/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:26:37 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/14 14:22:20 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


t_philo *add_new_philo(int nb)
{
	static int		id;
	t_philo			*philo;
	
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!id)
		id = nb;
	philo->id = id--;
	philo->state = THINKING;
	philo->fork_left = 1;
	philo->fork_right = 1;
	philo->last_eat = 0;
	philo->next = NULL;
	philo->prev = NULL;
	return (philo);
}
void	init_table(t_table **table, int nb)
{
	*table = malloc(sizeof(t_table));
	(*table)->head = NULL;
	(*table)->tail = NULL;
	(*table)->nb_philo = nb;
}

void add_first(t_table *table, t_philo *new_philo)
{
	if (!new_philo)
		return ;
	if (!table->head)
	{
		table->head = new_philo;
		table->tail = new_philo;
	}
	else
	{
		new_philo->next = table->head;
		table->head->prev = new_philo;
		table->head = new_philo;
		table->head->prev = table->tail;
		table->tail->next = table->head;
	}
}