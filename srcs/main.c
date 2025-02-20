/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:24:40 by doley             #+#    #+#             */
/*   Updated: 2025/02/20 19:40:44 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool is_dead(t_philo philo)
{
	long long interval;
	long long current_time;

	pthread_mutex_lock(&philo.mutex_meals);
	current_time = get_time();
	if (current_time == -1)
		return (1);
	interval = current_time - philo.last_meal;
	if (interval >= (long long)philo.data->time_to_die)
	{
		pthread_mutex_unlock(&philo.mutex_meals);
		return (1);
	}
	pthread_mutex_unlock(&philo.mutex_meals);
	return (0);
}

int	check_everybody_ate(t_philo *philos)
{
	size_t	i;

	i = 0;
	if (philos->data->nb_of_meals == 0)
		return (1);
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

void ft_join_all(t_philo *philos)
{
	size_t i;

	i = 0;
	while (i < (size_t)philos->data->nb_of_philo)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_data data;
	t_philo *philos;

	philos = NULL;
	memset(&data, 0, sizeof(t_data));
	if (!ft_init(argc, argv, &data, &philos))
		return (1);
	ft_monitor(philos);
	ft_join_all(philos);
	ft_free_data(&data, 1);
	ft_free_philos(&philos, (size_t)data.nb_of_philo);
}
