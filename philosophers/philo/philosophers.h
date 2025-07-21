/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:19:41 by ginfranc          #+#    #+#             */
/*   Updated: 2025/07/21 11:36:27 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_vars	t_vars;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		philo;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_vars			*vars;
}	t_philo;

typedef struct s_vars
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_eat;
	long			start_time;
	int				stop;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	stop_mutex;
	t_philo			*philos;
}	t_vars;

void	ft_usleep(long time_in_ms);
long	get_time(void);
int		ft_atoi(const char *nptr);
int		ft_strlen(char *str);
int		init_forks(t_vars *vars);
int		init_philos(t_vars *vars);
int		start_threads(t_vars *vars);
void	*philo_routine(void	*arg);
void	print_action(t_philo *philo, char *action);
int		simulation_should_stop(t_vars *vars);
void	*monitor_philos(void *arg);
void	ft_closed(t_vars *vars);

#endif
