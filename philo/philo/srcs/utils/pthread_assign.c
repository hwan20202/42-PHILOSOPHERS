/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_assign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:47:39 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 18:04:07 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <utils.h>
#include <stdlib.h>

int	pthread_assign(void *p)
{
	((t_node *)p)->content = malloc(sizeof(pthread_t));
	if (!((t_node *)p)->content)
		return (console("pthread_assign : malloc failed", ERROR));
	return (0);
}
