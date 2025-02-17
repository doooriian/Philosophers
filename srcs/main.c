/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:24:40 by doley             #+#    #+#             */
/*   Updated: 2025/02/17 17:50:20 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_test(t_data data)
{
	printf("nb of philo is : %d\n", data.nb_of_philo);
	printf("time to die is : %d\n", data.time_to_die);
	printf("time to eat is : %d\n", data.time_to_eat);
	printf("time to sleep is : %d\n", data.time_to_sleep);
	printf("nb of meals is : %d\n", data.nb_of_meals);
	printf("start time is : %lld\n", data.start_time);
	printf("flag to stop is : %d\n", data.flag_stop);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philos;

	philos = NULL;
	memset(&data, 0, sizeof(t_data));
	if (!ft_init(argc, argv, &data, &philos))
		return (1);
	ft_test(data);
}
