/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:10:13 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/15 09:38:56 by tel-mouh         ###   ########.fr       */
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
void	init_table(t_table **table, int nb);
void	add_first(t_table *table, t_philo *new_philo);
void	ft_free(t_table **table);
void	parse(t_table *table, int argc, char **argv);
void	print_error_exit(char *s);