/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:56:14 by doley             #+#    #+#             */
/*   Updated: 2025/02/17 18:39:58 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_free_data(t_data *data)
{
	size_t	i;

	i = 0;
	if (data->print_mutex_initialized)
		pthread_mutex_destroy(&data->print_mutex);
	if (data->fork_mutex)
		free(data->fork_mutex);
	return (0);
}

int	ft_free_philos(t_philo **philos, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		pthread_mutex_destroy(&(*philos)[i].mutex_meals);
		i++;
	}
	free(*philos);
	*philos = NULL;
	return (0);
}

int	init_mutex_tab(t_data *data)
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
			return (ft_free_data(data));
		}
		i++;
	}
	return (1);
}
