/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:17:26 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/22 21:59:06 by tel-mouh         ###   ########.fr       */
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
		// printf("%d\n",philo->next->id);
		if (get_time(philo) - philo->last_eat >= philo->vars->table->time_to_die)
		{
			philo->vars->is_died = 1;
			return (printf("\n %ld %d died\n", get_time(philo), philo->id) ,1);
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
