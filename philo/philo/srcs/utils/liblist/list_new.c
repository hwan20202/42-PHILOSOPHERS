/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:47:23 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 15:47:24 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "structures.h"
#include "utils.h"

void	list_init(t_list *list)
{
	list->head = 0;
	list->size = 0;
}

t_list	*list_new(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
	{
		printf("list_new : malloc failed");
		return (0);
	}
	list_init(list);
	return (list);
}
