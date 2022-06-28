/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:10:13 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/27 23:07:07 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include "types.h"
#include "utils.h"

t_philo	*add_new_philo(int nb);
int		parse(int argc, char **argv);
void	print_error(char *s);
int		init(t_vars *vars, int argc, char **argv);
void	*philo_routine(void *philo);
int		print_states(t_philo *philo, int state);
long	get_time(t_philo *philo);
int		thinking(t_philo *philo);
int		eating(t_philo *philo);
int		sleeping(t_philo *philo);
int		do_until(int (*thinking)(t_philo *), int (*sleeping)(t_philo *), int (*eating)(t_philo *), t_philo *philo);
void	*check_die(void	*philo);
void	ft_usleep(long time, t_philo *philo);
long	get_times(t_philo *philo);
int		take_forks(t_philo *philo, int *i);
int		realese_forks(t_philo *philo);
int		create_process(t_vars *vars);
int		send_kill(pid_t *pids, int nb, pid_t pid_rec);