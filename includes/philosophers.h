/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:26:41 by doley             #+#    #+#             */
/*   Updated: 2025/02/16 16:35:53 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>     // printf
# include <string.h>    // memset
# include <stdlib.h>    // malloc, free
# include <unistd.h>    // write, usleep
# include <pthread.h>   // thread related
# include <stdbool.h>	// bool
# include <sys/time.h>  // gettimeofday

typedef struct s_data
{
	int				nb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_meals;
	bool			flag_stop;
	long long		start_time;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*fork_mutex;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long long		last_meal;
	t_data			data;
	pthread_t		thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
}	t_philo;

int	ft_parsing(int argc, char **argv, t_data *input);

#endif
