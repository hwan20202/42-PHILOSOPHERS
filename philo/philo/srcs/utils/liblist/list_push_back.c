/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:47:25 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 15:47:26 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structures.h"
#include "utils.h"

t_node	*list_end(t_list *list)
{
	t_node	*end;

	if (!list)
		return (0);
	end = list->head->prev;
	return (end);
}

int	list_push_back(t_list *list, t_node *node)
{
	t_node	*end;

	if (!list || !node)
		return (ERROR);
	if (!list->head)
	{
		list->head = node;
		node->prev = node;
		node->next = node;
		list->size++;
	}
	else
	{
		end = list_end(list);
		list->head->prev = node;
		end->next = node;
		node->prev = end;
		node->next = list->head;
		list->size++;
	}
	return (0);
}
