/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:50:07 by doley             #+#    #+#             */
/*   Updated: 2025/02/20 16:07:42 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_flags(t_philo *philo)
{
	bool	local_flag_stop;
	bool	local_flag_start;

	local_flag_stop = 0;
	local_flag_start = 0;
	while (!local_flag_stop && !local_flag_start)
	{
		pthread_mutex_lock(&philo->data->flag_mutex);
		local_flag_stop = philo->data->flag_stop;
		local_flag_start = philo->data->flag_start;
		pthread_mutex_unlock(&philo->data->flag_mutex);
		usleep(100);
	}
	if (local_flag_stop)
		return (0);
	return (1);
}

void	print_messages(t_philo *philo, char *message)
{
	long long	time;

	time = get_time() - philo->data->start_time;
	if (time == -1)
	{
		pthread_mutex_lock(&philo->data->flag_mutex);
		philo->data->flag_stop = 1;
		pthread_mutex_unlock(&philo->data->flag_mutex);
	}
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%lld %d %s", time, philo->id, message);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

int	enough_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_meals);
	if (philo->meals_eaten < philo->data->nb_of_meals)
	{
		pthread_mutex_unlock(&philo->mutex_meals);
		return (1);
	}
	pthread_mutex_unlock(&philo->mutex_meals);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!check_flags(philo))
		return (NULL);
	while (1)
	{
		if (!ft_eat(philo))
			return (NULL);
		if (!ft_sleep(philo))
			return (NULL);
		print_messages(philo, "is thinking\n");
		if (!enough_eaten(philo))
			return (NULL);
	}
}
