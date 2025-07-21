/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 09:10:30 by ginfranc          #+#    #+#             */
/*   Updated: 2025/07/21 11:36:31 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_forks(t_vars *vars)
{
	int	i;

	vars->forks = malloc(sizeof(pthread_mutex_t) * vars->n_philos);
	if (!vars->forks)
		return (1);
	i = 0;
	while (i < vars->n_philos)
	{
		if (pthread_mutex_init(&vars->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	init_philos(t_vars *vars)
{
	int	i;

	vars->philos = malloc(sizeof(t_philo) * vars->n_philos);
	if (!vars->philos)
		return (1);
	i = 0;
	while (i < vars->n_philos)
	{
		vars->philos[i].id = i + 1;
		vars->philos[i].meals_eaten = 0;
		vars->philos[i].last_meal_time = get_time();
		vars->philos[i].vars = vars;
		if (pthread_mutex_init(&vars->philos[i].meal_mutex, NULL) != 0)
			return (1);
		vars->philos[i].left_fork = &vars->forks[i];
		vars->philos[i].right_fork = &vars->forks[(i + 1) % vars->n_philos];
		i++;
	}
	return (0);
}

int	start_threads(t_vars *vars)
{
	int	i;

	i = 0;
	pthread_mutex_init(&vars->print_mutex, NULL);
	pthread_mutex_init(&vars->stop_mutex, NULL);
	while (i < vars->n_philos)
	{
		if (pthread_create(&vars->philos[i].philo, NULL,
				&philo_routine, &vars->philos[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

void	ft_closed(t_vars *vars)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&vars->print_mutex);
	pthread_mutex_destroy(&vars->stop_mutex);
	free(vars->philos);
	while (++i < vars->n_philos)
		pthread_mutex_destroy(&vars->forks[i]);
	free(vars->forks);
}

