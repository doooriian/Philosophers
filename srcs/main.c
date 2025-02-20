/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:24:40 by doley             #+#    #+#             */
/*   Updated: 2025/02/20 17:01:11 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_print_data(t_data data)
{
	printf("nb of philo is : %d\n", data.nb_of_philo);
	printf("time to die is : %d\n", data.time_to_die);
	printf("time to eat is : %d\n", data.time_to_eat);
	printf("time to sleep is : %d\n", data.time_to_sleep);
	printf("nb of meals is : %d\n", data.nb_of_meals);
	printf("start time is : %lld\n", data.start_time);
	printf("flag to stop is : %d\n", data.flag_stop);
}

void	ft_print_philos(t_philo *philos, int nb_of_philo)
{
    int i;

    i = 0;
    while (i < nb_of_philo)
    {
        printf("  Philo %d:\n", philos[i].id);
        printf("  Meals eaten: %d\n", philos[i].meals_eaten);
        printf("  Last meal time: %lld\n", philos[i].last_meal);
        printf("  Left fork address: %p\n", (void *)philos[i].left_fork);
        printf("  Right fork address: %p\n", (void *)philos[i].right_fork);
        printf("  Data pointer: %p\n", (void *)philos[i].data);
        printf("---------------------------------\n");
        i++;
    }
}
bool	is_dead(t_philo philo)
{
	long long	interval;
	long long	current_time;

	pthread_mutex_lock(&philo.mutex_meals);
	current_time = get_time();
	if (current_time == -1)
		return (1);
	interval = philo.last_meal + current_time;
	if (interval < (long long)philo.data->time_to_die)
	{
		pthread_mutex_unlock(&philo.mutex_meals);
		return (1);
	}
	pthread_mutex_unlock(&philo.mutex_meals);
	return (0);
}

// int	check_everybody_ate(t_philo *philos)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < (size_t)philos->data->nb_of_philo)
// 	{
// 		pthread_mutex_lock(&philos[i].mutex_meals);
// 		if (philos[i].meals_eaten < philos->data->nb_of_meals)
// 			return (0);
// 		pthread_mutex_unlock(&philos[i].mutex_meals);
// 		i++;
// 	}
// 	return (1);
// }

// void	ft_monitor(t_philo *philos)
// {
// 	size_t	i;
// 	bool 	local_stop;

// 	i = 0;
// 	pthread_mutex_lock(&philos->data->flag_mutex);
// 	local_stop = philos->data->flag_stop;
// 	pthread_mutex_unlock(&philos->data->flag_mutex);
// 	while (!local_stop)
// 	{
// 		i = 0;
// 		usleep(10);
// 		while (i < (size_t)philos->data->nb_of_philo)
// 		{
// 			if (is_dead(philos[i]))
// 			{
// 				pthread_mutex_lock(&philos->data->flag_mutex);
// 				print_messages(&philos[i], "is dead\n");
// 				philos->data->flag_stop = 1;
// 				pthread_mutex_unlock(&philos->data->flag_mutex);
// 				printf("test");
// 				return ;
// 			}
// 			i++;
// 		}
// 	}
// }

void	ft_join_all(t_philo *philos)
{
	size_t	i;

	i = 0;
	while (i < (size_t)philos->data->nb_of_philo)
	{
		pthread_join(philos->thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philos;

	philos = NULL;
	memset(&data, 0, sizeof(t_data));
	if (!ft_init(argc, argv, &data, &philos))
		return (1);
	// ft_monitor(philos);
	ft_join_all(philos);
	// ft_print_data(data);
	// ft_print_philos(philos, data.nb_of_philo);
}
