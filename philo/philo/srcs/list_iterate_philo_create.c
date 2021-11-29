/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterate_philo_create.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:47:47 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 18:04:32 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "philo.h"
#include "utils.h"

int	philo_create(t_node *pth_n, t_node *phi_n)
{
	if (pthread_create(pth_n->content, NULL, philo_life, phi_n->content))
		return (console("philo manage : thread cread failed", ERROR));
	if (pthread_detach(*(pthread_t *)(pth_n->content)))
		return (console("philo manage : thread detach failed", ERROR));
	return (0);
}

int	list_iterate_philo_create(t_list *pth_l, t_list *phi_l, t_list *mut_l_print)
{
	t_node				*pth_n;
	t_node				*phi_n;
	t_node				*mut_n_print;
	unsigned long long	cur_time;
	int					i;

	i = 1;
	pth_n = pth_l->head;
	phi_n = phi_l->head;
	mut_n_print = mut_l_print->head;
	cur_time = get_cur_time();
	while (i++ <= phi_l->size)
	{
		((t_philo *)phi_n->content)->start = cur_time;
		((t_philo *)phi_n->content)->cur = cur_time;
		((t_philo *)phi_n->content)->latest = cur_time;
		((t_philo *)phi_n->content)->print_lock = mut_n_print->content;
		if (philo_create(pth_n, phi_n))
			return (ERROR);
		pth_n = pth_n->next;
		phi_n = phi_n->next;
		mut_n_print = mut_n_print->next;
	}
	return (0);
}
