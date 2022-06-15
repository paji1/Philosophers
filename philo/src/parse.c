/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 09:29:11 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/15 10:07:21 by tel-mouh         ###   ########.fr       */
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

void print_error_exit(char *s)
{
	ft_putstr_fd("\033[0;31m", 2);
	write(2, "Error:\n",7);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\033[0m", 2);
	exit(EXIT_FAILURE);	
}

static void check_all_arguments(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		print_error_exit("Invalid number of ARGUMENTS\n");
	if (ft_is_str_nb(argv[1]))
		print_error_exit("First Argument must be all digits (Nb of \
			PHILOSOPHERS)");
	if (ft_is_str_nb(argv[2]))
		print_error_exit("Second Argument must be all digits (time to die)\n");
	if (ft_is_str_nb(argv[3]))
		print_error_exit("Third Argument must be all digits (time to eath)\n");
	if (ft_is_str_nb(argv[4]))
		print_error_exit("Fourth Argument must be all digit (time to sleep)\n");
}

void parse(t_table *table, int argc, char **argv)
{
	check_all_arguments(argc, argv);
	
}