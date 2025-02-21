/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:50:07 by doley             #+#    #+#             */
/*   Updated: 2025/02/21 16:44:25 by doley            ###   ########.fr       */
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
	long long		time;

	pthread_mutex_lock(&philo->data->print_mutex);
    if (philo->data->someone_died)
    {
        pthread_mutex_unlock(&philo->data->print_mutex);
        return;
    }
	pthread_mutex_unlock(&philo->data->print_mutex);
	time = get_time() - philo->data->start_time;
	if (time == -1)
	{
		pthread_mutex_lock(&philo->data->flag_mutex);
		philo->data->flag_stop = 1;
		pthread_mutex_unlock(&philo->data->flag_mutex);
		return ;
	}
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%lld %d %s", time, philo->id, message);
	if (message[0] == 'd')
		philo->data->someone_died = 1;
	pthread_mutex_unlock(&philo->data->print_mutex);
}

static int	enough_eaten(t_philo *philo)
{
	if (philo->data->nb_of_meals == 0)
		return (0);
	pthread_mutex_lock(&philo->mutex_meals);
	if (philo->meals_eaten < philo->data->nb_of_meals)
	{
		pthread_mutex_unlock(&philo->mutex_meals);
		return (0);
	}
	pthread_mutex_unlock(&philo->mutex_meals);
	return (1);
}

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (!check_flags(philo))
		return (NULL);
	if (philo->id % 2)
		usleep(500);
	while (1)
	{
		if (!ft_eat(philo))
			break ;
		if (!ft_sleep(philo))
			break ;
		print_messages(philo, "is thinking\n");
		if (philo->data->nb_of_philo % 2 && (philo->data->time_to_think > 0))
			usleep(philo->data->time_to_think * 0.8 * 1000);
		if (enough_eaten(philo))
			break ;
		usleep(100);
	}
	return (NULL);
}

void	*routine_one(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->right_fork);
	print_messages(philo, "has taken a fork\n");
	while (1)
	{
		pthread_mutex_lock(&philo->data->flag_mutex);
		if (philo->data->flag_stop == 1)
			break ;
		pthread_mutex_unlock(&philo->data->flag_mutex);
		usleep(100);
	}
	pthread_mutex_unlock(&philo->data->flag_mutex);
	pthread_mutex_unlock(philo->right_fork);
	return (NULL);
}
