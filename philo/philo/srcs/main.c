/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:47:52 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 17:57:58 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include <stdlib.h>

int	isnegative(int num)
{
	if (num < 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_rule	*rule;
	t_l		*l;

	if (argc < 5 || argc > 6)
		return (console("usage : number_of_philo, time_to_die,\
		time_to_eat, time_to_sleep, [number_of_times_each_philosopher_must_eat]"
				, ERROR));
	rule = (t_rule *)get_rule(argc, argv);
	if (!rule)
		return (console("argument must be integer.", ERROR));
	if (isnegative(rule->number_of_philo) || rule->number_of_philo > 200
		|| rule->time_to_die < 60 || rule->time_to_eat < 60
		|| rule->time_to_sleep < 60)
		return (console("invalid value", ERROR));
	l = malloc(sizeof(t_l));
	if (!l)
		return (console("main : malloc failed", ERROR));
	if (philo_manage(rule, l))
		return (ERROR);
	return (0);
}
