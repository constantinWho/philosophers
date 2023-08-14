/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:13:29 by chustei           #+#    #+#             */
/*   Updated: 2023/08/14 14:27:45 by chustei          ###   ########.fr       */
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

int	check_input(int *nums, int ac, char **av)
{
	nums = get_args(ac - 1, &av[1]);
	if (!nums || !valid_args(nums, ac - 1))
		return (0);
	return (1);
}

/* void	init_args(t_arg *args, int *nums)
{
	args->num_of_philos = nums[0];
	args->time_to_die = nums[1];
	args->time_to_eat = nums[2];
	args->time_to_sleep = nums[3];
	if (nums[4])
		args->num_must_eat = nums[4];
} */

int	main(int ac, char **av)
{
	int				*nums;
	t_arg			args;

	nums = NULL;
	if (ac >= 5 && ac <= 6)
	{
		if (!check_input(nums, ac, av))
			return (0);
		args.num_of_philos = nums[0];
		args.time_to_die = nums[1];
		args.time_to_eat = nums[2];
		args.time_to_sleep = nums[3];
		if (nums[4])
			args.num_must_eat = nums[4];
/* 		init_args(args, nums); */
		printf("num_of_philos: %d\n", args.num_of_philos);
		printf("time_to_die: %d\n", args.time_to_die);
		printf("time_to_eat: %d\n", args.time_to_eat);
		printf("time_to_sleep: %d\n", args.time_to_sleep);
		if (nums[4])
			printf("num_must_eat: %d\n", args.num_must_eat);
	}
	else
		printf("Error: Please Provide 4 or 5 Arguments\n");
	free(nums);
	return (0);
}
