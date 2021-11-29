/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rule.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:47:44 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 16:41:32 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include "structures.h"
#include <stdlib.h>

t_rule	*get_rule(int argc, char **argv)
{
	t_rule	*rule;

	rule = malloc(sizeof(t_rule));
	if (!rule)
	{
		console("get_rule : malloc failed", 0);
		return (0);
	}
	if (get_argu(argv[1], &rule->number_of_philo)
		|| get_argu(argv[2], &rule->time_to_die)
		|| get_argu(argv[3], &rule->time_to_eat)
		|| get_argu(argv[4], &rule->time_to_sleep))
		return (0);
	if (argc == 6)
	{
		if (get_argu(argv[5], &rule->count_to_must_eat))
		{
			console("get_rule : get_argu failed", 0);
			return (0);
		}
	}
	else
		rule->count_to_must_eat = -1;
	return (rule);
}
