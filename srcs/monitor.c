/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:29:27 by doley             #+#    #+#             */
/*   Updated: 2025/02/21 14:56:40 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"


static bool is_dead(t_philo philo)
{
	long long interval;
	long long current_time;

	current_time = get_time();
	if (current_time == -1)
		return (1);
	pthread_mutex_lock(&philo.mutex_meals);
	interval = current_time - philo.last_meal;
	if (interval >= (long long)philo.data->time_to_die)
	{
		pthread_mutex_unlock(&philo.mutex_meals);
		return (1);
	}
	pthread_mutex_unlock(&philo.mutex_meals);
	return (0);
}

static int	check_everybody_ate(t_philo *philos)
{
	size_t	i;

	i = 0;
	if (philos->data->nb_of_meals == 0)
		return (0);
	while (i < (size_t)philos->data->nb_of_philo)
	{
		pthread_mutex_lock(&philos[i].mutex_meals);
		if (philos[i].meals_eaten < philos->data->nb_of_meals)
		{
			pthread_mutex_unlock(&philos[i].mutex_meals);
			return (0);
		}
		pthread_mutex_unlock(&philos[i].mutex_meals);
		i++;
	}
	return (1);
}

void	ft_monitor(t_philo *philos)
{
	size_t	i;
	bool 	local_stop;

	i = 0;
	pthread_mutex_lock(&philos->data->flag_mutex);
	local_stop = philos->data->flag_stop;
	pthread_mutex_unlock(&philos->data->flag_mutex);
	while (!local_stop && !check_everybody_ate(philos))
	{
		i = 0;
		usleep(10);
		while (i < (size_t)philos->data->nb_of_philo)
		{
			if (is_dead(philos[i]))
			{
				pthread_mutex_lock(&philos->data->flag_mutex);
				philos->data->flag_stop = 1;
				print_messages(&philos[i], "is dead\n");
				pthread_mutex_unlock(&philos->data->flag_mutex);
				return ;
			}
			i++;
		}
	}
}
