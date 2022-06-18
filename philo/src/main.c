/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:17:26 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/18 23:06:48 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/philo.h"

void print_states(t_philo *philo, int state)
{
	printf("\n%ld ", philo->vars->current_time.tv_usec - philo->vars->eposh.tv_usec);
	if (state == THINKING)
		printf("philo %d is thinking " ,philo->id);
	else if (state == SLEPPING)
		printf("philo %d is SLEPPING " ,philo->id);
	else if (state == EATING)
		printf("philo %d is EATING " ,philo->id);
	else if (state == TAKE_LEFT)
		printf("philo %d take left fork ",philo->id);
	else if (state == TAKE_RIGHT)
		printf("philo %d take right fork ",philo->id);
}

void	*philo_routine(void *var)
{
	t_philo *philo;
	int n;
	
	
	philo = (t_philo *)var;
	n = philo->id -1;;
	while (1)
	{
		if (philo->state == THINKING)
		{
		gettimeofday(&philo->vars->current_time, NULL);
			print_states(philo, THINKING);
			pthread_mutex_lock(&philo->vars->fork[n]);
			print_states(philo, TAKE_LEFT);
			pthread_mutex_lock(&philo->vars->fork[(n + 1) % philo->vars->table->nb_philo]);
			print_states(philo, TAKE_RIGHT);
		gettimeofday(&philo->vars->current_time, NULL);
			philo->state = EATING;
		}
		if (philo->state == SLEPPING)
		{
		gettimeofday(&philo->vars->current_time, NULL);
			print_states(philo, SLEPPING);
			usleep(philo->vars->table->time_to_sleep * 1000);
			philo->state = THINKING;
		}
		if (philo->state == EATING)
		{
		gettimeofday(&philo->vars->current_time, NULL);
			print_states(philo, EATING);
			usleep(philo->vars->table->time_to_eat * 1000);
			pthread_mutex_unlock(&philo->vars->fork[n]);
			pthread_mutex_unlock(&philo->vars->fork[(n + 1)%philo->vars->table->nb_philo]);
			philo->state = SLEPPING;
		}
	}
	return NULL;
}

int main(int argc, char **argv)
{
	t_vars vars;

	if (parse(argc, argv))
		return (1);
	if (init(&vars, argc, argv))
		return (1);		
	int i = -1;
	while (++i < vars.table->nb_philo)
		pthread_join(vars.threads[i], NULL);
	free(vars.threads);
	return (ft_free(&vars.table), 0);
}
