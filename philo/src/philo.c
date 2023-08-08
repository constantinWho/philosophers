/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:13:29 by chustei           #+#    #+#             */
/*   Updated: 2023/08/08 19:06:21 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	long long int	res;
	long long int	sign;

	res = 0;
	sign = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
		sign *= -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	return (res * sign);
}

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
			printf("Error: %s is not numeric nor positive", av[i]);
			free(args);
			return (NULL);
		}
		args[i] = ft_atoi(av[i]);
		i++;
	}
	return (args);
}

int	main(int ac, char **av)
{
	int	*args;

	args = NULL;
	if (ac >= 5 && ac <= 6)
	{
		args = get_args(ac - 1, &av[1]);
		if (!args)
			return (0);
		int i = 0;
		while (i < ac - 1)
		{
			if (args[0] > 200)
			{
				printf("Error: too many Philos\n");
				free(args);
				return (0);
			}
			if (args[i] < 1)
			{
				printf("Error: %i is smaller then 1\n", args[i]);
				free(args);
				return (0);
			}
			i++;
		}
	}
	else
		printf("WRONG amount of args in %s\n", av[0]);
	free(args);
	return (0);
}
