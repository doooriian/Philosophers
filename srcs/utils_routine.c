/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:26:32 by doley             #+#    #+#             */
/*   Updated: 2025/02/22 15:19:39 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_sleep(t_philo *philo)
{
	print_messages(philo, "is sleeping\n");
	return (ft_usleep(philo->data->time_to_sleep, philo->data));
}

static int	safe_lock(t_philo *philo, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(&philo->data->flag_mutex);
	if (philo->data->flag_stop == 1)
	{
		pthread_mutex_unlock(&philo->data->flag_mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->flag_mutex);
	pthread_mutex_lock(mutex);
	return (1);
}

static int	take_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		if (!safe_lock(philo, philo->left_fork))
			return (0);
		print_messages(philo, "has taken a fork\n");
		if (!safe_lock(philo, philo->right_fork))
		{
			pthread_mutex_unlock(philo->left_fork);
			return (0);
		}
		print_messages(philo, "has taken a fork\n");
	}
	else
	{
		if (!safe_lock(philo, philo->right_fork))
			return (0);
		print_messages(philo, "has taken a fork\n");
		if (!safe_lock(philo, philo->left_fork))
		{
			pthread_mutex_unlock(philo->right_fork);
			return (0);
		}
		print_messages(philo, "has taken a fork\n");
	}
	return (1);
}

int	ft_eat(t_philo *philo)
{
	if (!check_flags(philo))
		return (0);
	if (!take_forks(philo))
		return (0);
	print_messages(philo, "is eating\n");
	if (!ft_usleep(philo->data->time_to_eat, philo->data))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	pthread_mutex_lock(&philo->mutex_meals);
	philo->meals_eaten++;
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->mutex_meals);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (1);
}
