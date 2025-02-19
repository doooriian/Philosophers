/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:50:07 by doley             #+#    #+#             */
/*   Updated: 2025/02/19 16:28:33 by doley            ###   ########.fr       */
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

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	check_flags(philo);
	// a faire...
}
