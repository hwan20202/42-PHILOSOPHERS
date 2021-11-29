/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:47:21 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 18:00:05 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"

int	list_iterator(t_list *list, int (*fp)(void *))
{
	t_node	*n;

	if (!list || !fp)
		return (ERROR);
	n = list->head;
	while (list->head)
	{
		if (fp((void *)n))
			return (ERROR);
		if (n->next == list->head)
			break ;
		n = n->next;
	}
	return (0);
}
