/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:13:29 by chustei           #+#    #+#             */
/*   Updated: 2023/08/08 14:04:39 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int ac, char **av)
{
	if (ac >= 5 && ac <= 6)
		printf("RIGHT amount of args in %s\n", av[0]);
	else
		printf("WRONG amount of args in %s\n", av[0]);
	return (0);
}
