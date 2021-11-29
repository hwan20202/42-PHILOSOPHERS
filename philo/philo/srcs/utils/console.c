/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:47:30 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 17:29:38 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils.h"
#include "structures.h"
#include "philo.h"
#include <pthread.h>
#include <stdlib.h>

int	console(char *s, int return_value)
{
	printf("%s\n", s);
	return (return_value);
}

void	message(t_philo *philo, char *s1, char *s2)
{
	pthread_mutex_lock(philo->print_lock);
	philo->cur = get_cur_time();
	printf("%llu %s %d %s\n", (philo->cur - philo->start),
		s1, philo->own_num, s2);
	pthread_mutex_unlock(philo->print_lock);
}

int	mutex_lock(void *mut_n_print)
{
	return (pthread_mutex_lock(((t_node *)mut_n_print)->content));
}

void	dieing_message(t_list *mut_l_print, t_philo *philo)
{
	list_iterator(mut_l_print, mutex_lock);
	philo->cur = get_cur_time();
	printf("%llu %s %d %s\n", (philo->cur - philo->start),
		"ms", philo->own_num, "is died");
}
