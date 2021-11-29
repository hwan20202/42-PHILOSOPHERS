/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:27:21 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 15:47:19 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include <stdlib.h>

void	list_pop(t_list *list)
{
	t_node	*node;

	if (!list)
		return ;
	node = list->head;
	if (!node)
		return ;
	list->head = node->next;
	list->head->prev = node->prev;
	list->size--;
	free(node);
}

int	content_free(void *node)
{
	if (((t_node *)node)->content)
		free(((t_node *)node)->content);
	return (0);
}

void	list_free(t_list	*list)
{
	while (list->size > 0)
		list_pop(list);
	free(list);
}
