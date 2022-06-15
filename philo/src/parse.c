/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 09:29:11 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/15 10:24:06 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int ft_is_str_nb(char *nb_philo)
{
	while(*nb_philo)
	{
		if (!ft_isdigit(*nb_philo))
			return (1);
		nb_philo++;
	}
	return (0);
}

void print_error(char *s)
{
	ft_putstr_fd("\033[0;31m", 2);
	write(2, "Error:\n",7);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\033[0m", 2);
}

static int	check_all_arguments(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (print_error("Invalid number of ARGUMENTS\n"), 1);
	if (ft_is_str_nb(argv[1]))
		return (print_error\
			("First Argument must be all digits (Nb of PHILOSOPHERS)"), 1);
	if (ft_is_str_nb(argv[2]))
		return (print_error\
			("Second Argument must be all digits (time to die)\n"), 1);
	if (ft_is_str_nb(argv[3]))
		return (print_error\
			("Third Argument must be all digits (time to eath)\n"), 1);
	if (ft_is_str_nb(argv[4]))
		return (print_error\
			("Fourth Argument must be all digit (time to sleep)\n"), 1);
	return (0);
}

int	parse(t_table *table, int argc, char **argv)
{
	if (check_all_arguments(argc, argv))
		return (1);
	
}