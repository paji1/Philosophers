/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:17:26 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/23 02:02:00 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/philo.h"

void	*philo_routine(void *philo)
{
	if (do_until(thinking, sleeping, eating, (t_philo *)philo))
		return NULL;
	return philo;
}

int	check_all_philo(t_vars *vars)
{
	t_philo *philo;

	philo = vars->table->head;
	while (philo)
	{
		if (philo->vars->table->must_to_eat && philo->vars->n_num > philo->vars->table->nb_philo * philo->vars->table->must_to_eat)
		{	
			detach_threads(vars);
			return (1);
		}
		if (get_time(philo) - philo->last_eat >= philo->vars->table->time_to_die)
		{
			philo->vars->is_died = 1;
			join_threads(vars);
			return (printf("%ld %d died\n", get_time(philo), philo->id) ,1);
		}
		philo = philo->next;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_vars *vars;

	vars = malloc(sizeof(t_vars));
	if (parse(argc, argv))
		return (free(vars), 1);
	if (init(vars, argc, argv))
		return (free(vars), 1);
	if (check_all_philo(vars))
		return (free_all(vars), 0);
	join_threads(vars);
	if(vars->is_died)
		return (free_all(vars), 0);
	return (free(vars->threads), free(vars), ft_free(&vars->table), 0);
}
