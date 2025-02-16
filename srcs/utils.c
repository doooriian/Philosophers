/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:56:14 by doley             #+#    #+#             */
/*   Updated: 2025/02/16 19:52:39 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_free(t_data *data, t_philo *philos)
{
	size_t	i;
	
	i = 0;
	if (data->print_mutex_initialized)
		pthread_mutex_destroy(&data->print_mutex);
	while (i < data->nb_of_philo && philos)
	{
		if (philos[i].lf_mutex_initialized == 1)
			pthread_mutex_destroy(&philos[i].left_fork);
		if (philos[i].rf_mutex_initialized == 1)
			pthread_mutex_destroy(&philos[i].right_fork);
		i++;
	}
	if (philos)
		free(philos);
	if (data->fork_mutex)
		free(data->fork_mutex);
	return (0);
}

int	init_mutex_tab(t_data *data, t_philo *philos)
{
	int	i;
	
	i = 0;
	data->fork_mutex = malloc(sizeof(pthread_mutex_t) * data->nb_of_philo);
	if (!data->fork_mutex)
	{	
		printf("fork_mutex malloc failed\n");
		return (0);
	}
	while (i < data->nb_of_philo)
	{
		if (pthread_mutex_init(&data->fork_mutex[i], NULL) != 0)
		{	
			i--;
			while (i >= 0)
			{
				pthread_mutex_destroy(&data->fork_mutex[i]);
				i--;
			}
			return (ft_free(data, philos));
		}
		i++;
	}
	return (1);
}
