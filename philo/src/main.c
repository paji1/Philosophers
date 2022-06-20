/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:17:26 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/20 18:02:49 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/philo.h"
void sleeping(t_philo *philo)
{
	if (philo->state == SLEPPING)
	{
		print_states(philo, SLEPPING);
		usleep(philo->vars->table->time_to_sleep * 1000);
		print_states(philo, THINKING);
		philo->state = THINKING;
	}
}

void thinking(t_philo *philo)
{
	static int i;
	
	if (philo->state == THINKING)
	{
		if (!i && philo->id % 2)
			i = 1 , usleep(200);
		pthread_mutex_lock(&philo->vars->fork[philo->id - 1]);
		print_states(philo, TAKE_LEFT);
		pthread_mutex_lock(&philo->vars->fork[(philo->id) % philo->vars->table->nb_philo]);
		print_states(philo, TAKE_RIGHT);
		philo->state = EATING;
	}
}

void eating(t_philo *philo)
{
	if (philo->state == EATING)
	{
		print_states(philo, EATING);
		// philo->vars->is_died = 1;
		usleep(philo->vars->table->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->vars->fork[philo->id - 1]);
		pthread_mutex_unlock(&philo->vars->fork[(philo->id) % philo->vars->table->nb_philo]);
		philo->state = SLEPPING;
	}
}

void	*philo_routine(void *var)
{
	t_philo *philo;

	philo = (t_philo *)var;

	while (!philo->vars->is_died)
	{
		thinking(philo);
		sleeping(philo);
		eating(philo);
	}
	return NULL;
}

int main(int argc, char **argv)
{
	t_vars *vars;

	vars = malloc(sizeof(t_vars));
	if (parse(argc, argv))
		return (free(vars), 1);
	if (init(vars, argc, argv))
		return (free(vars), 1);
	t_philo *philo = vars->table->head;
	while (1)
	{
		if(vars->is_died)
			return printf("hello\n") ,0;
		philo = philo->next;
	}
	int i = -1;
	while (++i < vars->table->nb_philo)
		pthread_join(vars->threads[i], NULL);
	return (free(vars->threads), free(vars), ft_free(&vars->table), 0);
}
