/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_assign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:47:37 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 18:04:11 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <stdlib.h>

void	philo_init(void *p)
{
	((t_philo *)p)->own_num = 0;
	((t_philo *)p)->fir = 0;
	((t_philo *)p)->sec = 0;
	((t_philo *)p)->start = 0;
	((t_philo *)p)->cur = 0;
	((t_philo *)p)->latest = 0;
	((t_philo *)p)->rule = 0;
	((t_philo *)p)->eating_time = 0;
}

int	philo_assign(void *p)
{
	((t_node *)p)->content = malloc(sizeof(t_philo));
	if (!((t_node *)p)->content)
		return (console("philo_assign : malloc failed", ERROR));
	philo_init(((t_node *)p)->content);
	return (0);
}
