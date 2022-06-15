/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:03:17 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/14 13:56:36 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define THINKING	0
# define SLEPPING	1
# define EATING		2
# define DYE		3

typedef struct	s_philo
{
	int				id;
	int				state;
	int				fork_right;
	int				fork_left;
	int				last_eat;
	struct 			s_philo *next;
	struct 			s_philo *prev;
}	t_philo;
	
typedef struct s_table
{
	t_philo *head;
	t_philo *tail;
	int		nb_philo;
}	t_table;

#endif








