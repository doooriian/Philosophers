/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:24:40 by doley             #+#    #+#             */
/*   Updated: 2025/02/18 15:59:06 by doley            ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philos;

	philos = NULL;
	memset(&data, 0, sizeof(t_data));
	if (!ft_init(argc, argv, &data, &philos))
		return (1);
	ft_print_data(data);
	ft_print_philos(philos, data.nb_of_philo);
}
