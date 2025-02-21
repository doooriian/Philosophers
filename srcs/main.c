/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:24:40 by doley             #+#    #+#             */
/*   Updated: 2025/02/21 15:17:51 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	ft_join_all(t_philo *philos)
{
	size_t	i;

	i = 0;
	while (i < (size_t)philos->data->nb_of_philo)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philos;

	if (argc != 5 && argc != 6)
	{
		printf("wrong input\n");
		return (0);
	}
	philos = NULL;
	memset(&data, 0, sizeof(t_data));
	if (!ft_init(argc, argv, &data, &philos))
		return (1);
	ft_monitor(philos);
	ft_join_all(philos);
	ft_free_data(&data, 1);
	ft_free_philos(&philos, (size_t)data.nb_of_philo);
}
