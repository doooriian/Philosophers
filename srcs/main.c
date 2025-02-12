/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:24:40 by doley             #+#    #+#             */
/*   Updated: 2025/02/14 17:11:18 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	input_init(t_input *input)
{
	input->nb_of_philo = 0;
	input->time_to_die = 0;
	input->time_to_eat = 0;
	input->time_to_sleep = 0;
	input->nb_of_meals = 0;
}

int	main(int argc, char **argv)
{
	t_input	input;

	input_init(&input);
	if (!ft_parsing(argc, argv, &input))
	{
		printf("wrong input");
		return (1);
	}
	printf("nb of philo is : %d\n", input.nb_of_philo);
	printf("time to die is : %d\n", input.time_to_die);
	printf("time to eat is : %d\n", input.time_to_eat);
	printf("time to sleep is : %d\n", input.time_to_sleep);
	printf("nb of meals is : %d\n", input.nb_of_meals);
}
