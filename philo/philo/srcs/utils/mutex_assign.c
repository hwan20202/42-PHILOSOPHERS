/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_assign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:47:35 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 18:04:16 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <utils.h>
#include <stdlib.h>

int	mutex_assign(void *p)
{
	((t_node *)p)->content = malloc(sizeof(pthread_mutex_t));
	if (!((t_node *)p)->content)
		return (console("mutex_assign : malloc failed", ERROR));
	return (0);
}
