/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:03:17 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/22 17:39:34 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define THINKING	0
# define SLEPPING	1
# define EATING		2
# define DIED		3
# define TAKE_RIGHT 4
# define TAKE_LEFT 5

typedef struct s_vars t_vars;
typedef struct timeval t_timeval;

typedef struct	s_philo
{
	int				id;
	int				state;
	long			last_eat;
	t_vars			*vars;
	struct 			s_philo *next;
	struct 			s_philo *prev;
}	t_philo;
	
typedef struct s_table
{
	t_philo 		*head;
	t_philo 		*tail;
	int				time_to_die;
	int				time_to_eat;
	int	 			time_to_sleep;
	int 			must_to_eat;
	int				nb_philo;
}	t_table;

typedef struct s_vars
{
	t_timeval		eposh;
	t_timeval		current_time;
	void 			*data;
	pthread_mutex_t	*fork;
	t_table			*table;
	pthread_t		*threads;
	int				is_died;
}t_vars;
#endif








