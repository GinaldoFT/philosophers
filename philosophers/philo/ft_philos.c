/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 10:10:42 by ginfranc          #+#    #+#             */
/*   Updated: 2025/07/28 11:26:27 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_routine_utils(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
	}
	pthread_mutex_lock(&philo->meal_mutex);
	print_action(philo, "is eating");
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	ft_usleep(philo->vars->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	print_action(philo, "is sleeping");
	ft_usleep(philo->vars->time_to_sleep);
	print_action(philo, "is thinking");
}

void	*philo_routine(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(60);
	if (philo->vars->n_philos == 1)
	{
		print_action(philo, "has taken a fork");
		ft_usleep(philo->vars->time_to_die);
		return (NULL);
	}
	while (!simulation_should_stop(philo->vars))
	{
		philo_routine_utils(philo);
	}
	return (NULL);
}

int	all_philos_ate_enough(t_vars *vars)
{
	int	i;
	int	done;

	if (vars->n_eat < 0)
		return (0);
	i = 0;
	done = 1;
	while (i < vars->n_philos)
	{
		pthread_mutex_lock(&vars->philos[i].meal_mutex);
		if (vars->philos[i].meals_eaten < vars->n_eat)
			done = 0;
		pthread_mutex_unlock(&vars->philos[i].meal_mutex);
		i++;
	}
	return (done);
}

static int	monitor_philos_utils(t_vars *vars, int i)
{
	if (vars->n_eat >= 0 && all_philos_ate_enough(vars))
	{
		pthread_mutex_lock(&vars->stop_mutex);
		vars->stop = 1;
		pthread_mutex_unlock(&vars->stop_mutex);
		return (1);
	}
	pthread_mutex_lock(&vars->philos[i].meal_mutex);
	if (get_time() - vars->philos[i].last_meal_time > vars->time_to_die)
	{
		pthread_mutex_unlock(&vars->philos[i].meal_mutex);
		pthread_mutex_lock(&vars->print_mutex);
		printf("%ld %d died\n", get_time() - vars->start_time,
			vars->philos[i].id);
		pthread_mutex_unlock(&vars->print_mutex);
		pthread_mutex_lock(&vars->stop_mutex);
		vars->stop = 1;
		pthread_mutex_unlock(&vars->stop_mutex);
		return (1);
	}
	pthread_mutex_unlock(&vars->philos[i].meal_mutex);
	return (0);
}

void	*monitor_philos(void *arg)
{
	t_vars	*vars;
	int		i;

	vars = (t_vars *)arg;
	while (!simulation_should_stop(vars))
	{
		i = 0;
		while (i < vars->n_philos)
		{
			if (monitor_philos_utils(vars, i) == 1)
				return (NULL);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
