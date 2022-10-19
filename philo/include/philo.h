/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:10:13 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/19 20:17:20 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "types.h"
# include "utils.h"

t_philo	*add_new_philo(int nb);
void	*init_table(t_table **table, int nb);
int		init_mutexes(t_vars *vars);
int		add_first(t_table *table, t_philo *new_philo);
void	ft_free(t_table **table);
int		parse(int argc, char **argv);
void	print_error(char *s);
int		init(t_vars *vars, int argc, char **argv);
void	*philo_routine(void *philo);
void	destroy_mutexs(t_vars *vars);
int		print_states(t_philo *philo, int state);
long	get_time(t_philo *philo);
int		thinking(t_philo *philo);
int		eating(t_philo *philo);
int		sleeping(t_philo *philo);
int		do_until(int (*thinking)(t_philo *), int (*sleeping)(t_philo *), \
	int (*eating)(t_philo *), t_philo *philo);
int		check_pass_time(t_philo *philo);
void	free_all(t_vars *vars);
void	ft_usleep(long time, t_philo *philo);
int		create_threads(t_vars *vars, int nb);
int		join_threads(t_vars *vars);
long	get_times(t_philo *philo);
int		take_forks(t_philo *philo, int *i);
int		realese_forks(t_philo *philo);
int		detach_threads(t_vars *vars);
#endif