/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:47:54 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 17:57:24 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "philo.h"
#include "utils.h"
#include <sys/time.h>
#include <unistd.h>

void	*philo_life(void *philo)
{
	if (!(((t_philo *)philo)->own_num % 2))
		usleep(EPSILON);
	while (1)
	{
		if (!try_eat(philo))
			message(philo, "ms", "is eating");
		if (!eating(philo))
			message(philo, "ms", "is sleeping");
		if (!sleeping(philo))
			message(philo, "ms", "is thinking");
	}
	return (0);
}

int	try_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fir);
	message(philo, "ms", "has taken a fork");
	pthread_mutex_lock(philo->sec);
	message(philo, "ms", "has taken a fork");
	return (0);
}

int	eating(t_philo *philo)
{
	unsigned long long	rec;

	rec = philo->cur;
	philo->latest = rec;
	while (1)
	{
		philo->cur = get_cur_time();
		if (philo->cur - rec >= (unsigned long long)philo->rule->time_to_eat)
			break ;
		usleep(EPSILON);
	}
	philo->eating_time++;
	pthread_mutex_unlock(philo->fir);
	pthread_mutex_unlock(philo->sec);
	return (0);
}

int	sleeping(t_philo *philo)
{
	unsigned long long	rec;

	rec = philo->cur;
	while (1)
	{
		philo->cur = get_cur_time();
		if (philo->cur - rec >= (unsigned long long)philo->rule->time_to_sleep)
			break ;
		usleep(EPSILON);
	}
	return (0);
}
