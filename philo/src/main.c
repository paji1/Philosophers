/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:17:26 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/15 10:17:08 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/philo.h"


// void	*philo(void *t)
// {
	
// }

int main(int argc, char **argv)
{
	t_table *table;

	if (parse(table, argc, argv))
		return (1);
	
	init_table(&table, 7);

	
	// ft_free(&table);
	return 0;
}