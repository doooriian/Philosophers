/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:24:40 by doley             #+#    #+#             */
/*   Updated: 2025/02/16 16:46:11 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!ft_parsing(argc, argv, &data))
		return (1);
	printf("nb of philo is : %d\n", data.nb_of_philo);
	printf("time to die is : %d\n", data.time_to_die);
	printf("time to eat is : %d\n", data.time_to_eat);
	printf("time to sleep is : %d\n", data.time_to_sleep);
	printf("nb of meals is : %d\n", data.nb_of_meals);
	printf("start time is : %lld\n", data.start_time);
}
