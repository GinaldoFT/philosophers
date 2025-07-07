/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:18:48 by ginfranc          #+#    #+#             */
/*   Updated: 2025/07/07 12:12:07 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_args(t_vars	*vars, char *av[], int ac)
{
	vars->n_philos = ft_atoi(av[1]);
	vars->time_to_die = ft_atoi(av[2]);
	vars->time_to_eat = ft_atoi(av[3]);
	vars->time_to_sleep = ft_atoi(av[4]);
	vars->n_eat = -1;
	if (ac == 6)
		vars->n_eat = ft_atoi(av[5]);
}

int	args_check(char *av[])
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (ft_strlen(av[i]) == 0)
			return (1);
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char *av[])
{
//	t_philo	philos;
	t_vars	vars;

	if (ac < 5 || ac > 6)
		return (1);
	if (args_check(av) == 1)
		return (1);
	set_args(&vars, av, ac);
	printf("%d\n", vars.n_philos);
	return (0);
}
