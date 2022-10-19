/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:26:37 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/19 20:04:57 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*add_new_philo(int nb)
{
	static int		id;
	t_philo			*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	if (!id)
		id = nb;
	philo->id = id--;
	philo->state = THINKING;
	philo->last_eat = 0;
	philo->next = NULL;
	philo->prev = NULL;
	return (philo);
}

void	*init_table(t_table **table, int nb)
{
	*table = malloc(sizeof(t_table));
	if (!(*table))
		return (NULL);
	(*table)->head = NULL;
	(*table)->tail = NULL;
	(*table)->nb_philo = nb;
	return ((void *)*table);
}

int	add_first(t_table *table, t_philo *new_philo)
{
	if (!new_philo)
		return (0);
	if (!table->head)
	{
		table->head = new_philo;
		table->head->next = new_philo;
		table->head->prev = new_philo;
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
	return (1);
}
