/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:26:41 by doley             #+#    #+#             */
/*   Updated: 2025/02/22 15:05:35 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct s_data
{
	int				nb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				nb_of_meals;
	long long		start_time;
	bool			someone_died;
	bool			flag_stop;
	bool			flag_start;
	pthread_mutex_t	flag_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*fork_mutex;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long long		last_meal;
	t_data			*data;
	pthread_t		thread;
	pthread_mutex_t	mutex_meals;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

//	init.c
int			ft_init(int argc, char **argv, t_data *input, t_philo **philos);

// monitor.c
void		ft_monitor(t_philo *philos);

// routine.c
int			check_flags(t_philo *philo);
void		print_messages(t_philo *philo, char *message);
void		*routine(void *arg);
void		*routine_one(void *arg);

// time.c
long long	get_time(void);
int			ft_usleep(int sleeping_time, t_data *data);

// utils_routine.c
int			ft_sleep(t_philo *philo);
int			ft_eat(t_philo *philo);

// utils.c
int			check_syntax(char *str);
int			ft_atoi_p(char *str);
int			ft_free_data(t_data *data, bool destroy_flag);
int			ft_free_philos(t_philo **philos, size_t index);
int			ft_init_one_philo(t_data *data, t_philo **philos);

#endif
