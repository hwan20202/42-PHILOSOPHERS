/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:47:28 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 18:03:45 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "structures.h"
#include "utils.h"

void	node_init(t_node *node)
{
	node->content = 0;
	node->prev = 0;
	node->next = 0;
}

t_node	*node_new(void)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
	{
		printf("node_new : malloc failed");
		return (0);
	}
	node_init(node);
	return (node);
}
