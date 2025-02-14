/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:26:41 by doley             #+#    #+#             */
/*   Updated: 2025/02/13 16:19:29 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>     // printf
# include <string.h>    // memset
# include <stdlib.h>    // malloc, free
# include <unistd.h>    // write, usleep
# include <pthread.h>   // thread related
# include <sys/time.h>  // gettimeofday

typedef struct s_input
{
	int	nb_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_of_meals;
}	t_input;

int	ft_parsing(int argc, char **argv, t_input *input);

#endif
