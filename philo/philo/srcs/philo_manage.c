/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:47:57 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 17:59:36 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "philo.h"
#include <pthread.h>
#include "utils.h"

int	list_ready(t_list **dest, int size, int (*fp)(void *))
{
	t_node	*n;
	int		i;

	i = 0;
	*dest = list_new();
	if (!dest || !fp || !*dest)
		return (ERROR);
	while (i++ < size)
	{
		n = node_new();
		if (!n)
		{
			list_free(*dest);
			return (ERROR);
		}
		list_push_back(*dest, n);
	}
	if (list_iterator(*dest, fp))
	{
		list_iterator(*dest, content_free);
		list_free(*dest);
		return (ERROR);
	}
	return (0);
}

int	mutex_init(void *p)
{
	if (pthread_mutex_init(((t_node *)p)->content, NULL))
		return (console("mutex_init : pthread_mutex_init failed", ERROR));
	return (0);
}

int	philo_manage(t_rule *rule, t_l *l)
{
	if (list_ready(&(l->pth_l), rule->number_of_philo, pthread_assign)
		|| list_ready(&(l->mut_l), rule->number_of_philo, mutex_assign)
		|| list_ready(&(l->phi_l), rule->number_of_philo, philo_assign)
		|| list_ready(&(l->mut_l_print), rule->number_of_philo, mutex_assign))
		return (ERROR);
	list_iterator(l->mut_l, mutex_init);
	list_iterator(l->mut_l_print, mutex_init);
	list_iterate_philo_set(l->phi_l, l->mut_l, rule);
	list_iterate_philo_create(l->pth_l, l->phi_l, l->mut_l_print);
	philo_monitor(l->phi_l, l->mut_l_print);
	return (0);
}
