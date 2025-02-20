/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:27:30 by doley             #+#    #+#             */
/*   Updated: 2025/02/20 14:56:54 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		printf("error getting time\n");
		return (-1);
	}
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

int	ft_usleep(int sleeping_time, t_data *data)
{
	long long	start;
	long long	current;

	start = get_time();
	if (start == -1)
		return (0);
	current = start;
	while (current - start < (long long)sleeping_time)
	{
		usleep(100);
		pthread_mutex_lock(&data->flag_mutex);
		if (data->flag_stop)
		{
			pthread_mutex_unlock(&data->flag_mutex);
			return (0);
		}
		pthread_mutex_unlock(&data->flag_mutex);
		current = get_time();
		if (current == -1)
			return (0);
	}
	return (1);
}
