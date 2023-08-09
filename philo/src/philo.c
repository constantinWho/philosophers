/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:13:29 by chustei           #+#    #+#             */
/*   Updated: 2023/08/09 13:55:58 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	valid_args(int *args, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (args[0] > 200)
		{
			printf("Error: Too Many Philos\n");
			free(args);
			return (0);
		}
		if (args[i] < 1)
		{
			printf("Error: Wrong Input\n");
			free(args);
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	*args;

	args = NULL;
	if (ac >= 5 && ac <= 6)
	{
		args = get_args(ac - 1, &av[1]);
		if (!args || !valid_args(args, ac - 1))
			return (0);
	}
	else
		printf("Error: Wrong Number of Args\n");
	free(args);
	return (0);
}
