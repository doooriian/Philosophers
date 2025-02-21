/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:56:14 by doley             #+#    #+#             */
/*   Updated: 2025/02/21 15:11:47 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_syntax(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '+')
	{
		if (!str[i + 1])
			return (0);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_p(char *str)
{
	size_t		i;
	long long	nb;

	i = 0;
	nb = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		nb = nb * 10 + str[i] - '0';
		i++;
		if (nb > 2147483647)
			return (0);
	}
	return ((int)nb);
}

int	ft_free_data(t_data *data, bool destroy_flag)
{
	size_t	i;

	i = 0;
	pthread_mutex_destroy(&data->print_mutex);
	if (data->fork_mutex)
	{
		while (i < (size_t)data->nb_of_philo)
		{
			pthread_mutex_destroy(&data->fork_mutex[i]);
			i++;
		}
		free(data->fork_mutex);
	}
	if (destroy_flag)
		pthread_mutex_destroy(&data->flag_mutex);
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

int	ft_init_one_philo(t_data *data, t_philo **philos)
{
	if (pthread_create(&(*philos)[0].thread, NULL, &routine_one_philo, &(*philos)[0]))
	{
		ft_free_philos(philos, (size_t)data->nb_of_philo);
		ft_free_data(data, 1);
		return (0);
	}
	return (1);
}
