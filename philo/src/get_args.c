/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:57:51 by chustei           #+#    #+#             */
/*   Updated: 2023/08/09 13:55:04 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	*get_args(int size, char **av)
{
	int	i;
	int	*args;

	i = 0;
	args = (int *)malloc(sizeof(int *) * size);
	while (av[i])
	{
		if (!isnum(av[i]))
		{
			printf("Error: Wrong Input");
			free(args);
			return (NULL);
		}
		args[i] = atoi(av[i]);
		i++;
	}
	return (args);
}
