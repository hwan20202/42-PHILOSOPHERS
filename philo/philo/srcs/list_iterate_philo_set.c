/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterate_philo_set.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:47:49 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 16:55:25 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "philo.h"
#include "utils.h"
#include <pthread.h>

int	philo_set(t_node *phi_n, t_node *mut_n, t_rule *rule, int own_num)
{
	if (!phi_n || !mut_n || !rule)
		return (ERROR);
	((t_philo *)phi_n->content)->own_num = own_num;
	if (((t_philo *)phi_n->content)->own_num < 0)
		return (ERROR);
	((t_philo *)phi_n->content)->rule = rule;
	if ((((t_philo *)phi_n->content)->own_num % 2))
	{
		((t_philo *)phi_n->content)->fir = mut_n->content;
		((t_philo *)phi_n->content)->sec = ((t_node *)mut_n->next)->content;
	}
	else
	{
		((t_philo *)phi_n->content)->fir = ((t_node *)mut_n->next)->content;
		((t_philo *)phi_n->content)->sec = mut_n->content;
	}
	return (0);
}

int	list_iterate_philo_set(t_list *phi_l, t_list *mut_l, t_rule *rule)
{
	t_node	*phi_n;
	t_node	*mut_n;
	int		i;

	i = 1;
	phi_n = phi_l->head;
	mut_n = mut_l->head;
	while (i <= phi_l->size)
	{
		if (philo_set(phi_n, mut_n, rule, i))
			return (ERROR);
		phi_n = phi_n->next;
		mut_n = mut_n->next;
		i++;
	}
	return (0);
}
