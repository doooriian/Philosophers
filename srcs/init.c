/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:07:53 by doley             #+#    #+#             */
/*   Updated: 2025/02/18 18:00:08 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	ft_init_input(int argc, char **argv, t_data *data)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		printf("gettimeofday failed\n");
		return (0);
	}
	data->nb_of_philo = ft_atoi_p(argv[1]);
	data->time_to_die = ft_atoi_p(argv[2]);
	data->time_to_eat = ft_atoi_p(argv[3]);
	data->time_to_sleep = ft_atoi_p(argv[4]);
	if (argc == 6)
		data->nb_of_meals = ft_atoi_p(argv[5]);
	if ((data->nb_of_philo == 0 || data->time_to_die == 0
		|| data->time_to_eat == 0 || data->time_to_sleep == 0)
		|| (argc == 6 && data->nb_of_meals == 0))
	{
		printf("wrong input");
		return (0);
	}
	data->start_time = tv.tv_sec * 1000LL + tv.tv_usec / 1000;
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (0);
	return (1);
}

static int	ft_init_philos(t_data *data, t_philo **philos)
{
	size_t	i;

	i = 0;
	*philos = malloc(sizeof(t_philo) * data->nb_of_philo);
	if (!*philos)
	{
		printf("philos malloc failed\n");
		return (0);
	}
	while (i < (size_t)data->nb_of_philo)
	{
		memset(&(*philos)[i], 0, sizeof(t_philo));
		(*philos)[i].id = i;
		(*philos)[i].data = data;
		(*philos)[i].last_meal = data->start_time;
		(*philos)[i].right_fork = &data->fork_mutex[i];
		(*philos)[i].left_fork = &data->fork_mutex[(i + 1) % data->nb_of_philo];
		if (pthread_mutex_init(&(*philos)[i].mutex_meals, NULL))
		{
			ft_free_data(data, 1);
			return(ft_free_philos(philos, i));
		}
		i++;
	}
	return (1);
}

static int	init_mutex_tab(t_data *data)
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
		if (pthread_mutex_init(&data->fork_mutex[i], NULL))
		{
			while (--i >= 0)
			{
				pthread_mutex_destroy(&data->fork_mutex[i]);
			}
			free(data->fork_mutex);
			data->fork_mutex = NULL;
			return (ft_free_data(data, 1));
		}
		i++;
	}
	return (1);
}

static int	ft_init_threads(t_data *data, t_philo **philos)
{
	size_t	i;

	i = 0;
	while (i < (size_t)data->nb_of_philo)
	{
		if (pthread_create(&(*philos)[i].thread, NULL, &routine, &(*philos)[i]))
		{
			ft_free_philos(philos, (size_t)data->nb_of_philo);
			ft_free_data(data, 1);
		}
	}
}

int	ft_init(int argc, char **argv, t_data *data, t_philo **philos)
{
	size_t	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (0);
	while (i < (size_t) argc)
	{
		if (!check_syntax(argv[i]))
			return (0);
		i++;
	}
	if (!ft_init_input(argc, argv, data))
		return (0);
	if (pthread_mutex_init(&data->flag_mutex, NULL))
		return (ft_free_data(data, 0));
	if (!init_mutex_tab(data))
		return (0);
	if (!ft_init_philos(data, philos))
		return (0);
	return (1);
}
