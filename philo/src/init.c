/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:10:37 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/15 13:53:24 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init(t_vars *vars, int argc, char **argv)
{
	int	nb;
	int	i;

	nb = atoi(argv[1]);
	i = -1;
	vars->table = NULL;
	if (!init_table(&vars->table, nb))
		return (ft_free(&vars->table), 1);
	while (++i < nb)
		if(!add_first(vars->table, add_new_philo(nb)))
			return (ft_free(&vars->table), 1);
	return (0);
}