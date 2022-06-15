/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:17:26 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/15 13:50:14 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/philo.h"


// void	*philo(void *t)
// {
	
// }

int main(int argc, char **argv)
{
	t_vars vars;

	if (parse(argc, argv))
		return (1);
	if (init(&vars, argc, argv))
		return (1);

	ft_free(&vars.table);
	return 0;
}
