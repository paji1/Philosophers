/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:10:13 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/15 13:37:50 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "../libft/include/libft.h"
#include "types.h"
#include <sys/time.h>

t_philo	*add_new_philo(int nb);
void	*init_table(t_table **table, int nb);
int		add_first(t_table *table, t_philo *new_philo);
void	ft_free(t_table **table);
int		parse(int argc, char **argv);
void	print_error(char *s);
int		init(t_vars *vars, int argc, char **argv);