/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:47:59 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 18:04:54 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "philo.h"
#include "utils.h"
#include <unistd.h>

int	philo_isdie(t_node *phi_n)
{
	((t_philo *)phi_n->content)->cur = get_cur_time();
	if ((((t_philo *)phi_n->content)->cur - ((t_philo *)phi_n->content)->latest)
		> (unsigned long long)((t_philo *)phi_n->content)->rule->time_to_die)
		return (ERROR);
	return (0);
}

int	philo_isenough(t_node *phi_n)
{
	if (!phi_n)
		return (0);
	if (((t_philo *)(phi_n->content))->eating_time < 0)
		return (0);
	if (((t_philo *)(phi_n->content))->eating_time
		>= (unsigned long)((t_philo *)phi_n->content)->rule->count_to_must_eat)
		return (1);
	return (0);
}

void	philo_monitor(t_list *phi_l, t_list *mut_l_print)
{
	int		enough;
	t_node	*phi_n;

	phi_n = phi_l->head;
	enough = 0;
	while (1)
	{
		if (philo_isdie(phi_n))
		{
			dieing_message(mut_l_print, phi_n->content);
			break ;
		}
		if (philo_isenough(phi_n))
			enough++;
		else
			enough = 0;
		if (enough >= phi_l->size)
			break ;
		phi_n = phi_n->next;
		usleep(EPSILON);
	}
}
