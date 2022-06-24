/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 09:29:11 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/24 16:41:49 by tel-mouh         ###   ########.fr       */
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
	if (argc == 6 && ft_is_str_nb(argv[5]))
		return (print_error\
			("Fourth Argument must be all digit (time to sleep)\n"), 1);
	return (0);
}
static int check_if_inrange(int argc, char **argv)
{
	int		i;
	char	*s;
	
	i = 0;
	while (++i < argc)
	{
		s = ft_itoa(ft_atoi((char *)argv[i]));
		if (ft_strcmp((const char *)argv[i],s))
		return (free(s), print_error\
			("the number not in range of integer \n"), 1);
		free(s);
	}
	return (0);
}

int	parse(int argc, char **argv)
{
	if (check_all_arguments(argc, argv))
		return (1);
	if (check_if_inrange(argc, argv))
		return (1);
	return (0);
}