/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cur_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:47:41 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 17:29:15 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include <sys/time.h>

unsigned long long	get_cur_time(void)
{
	unsigned long long	cur;
	struct timeval		unix;

	if (gettimeofday(&unix, NULL) == -1)
		return (console("cur_time_update : gettime failed", ERROR));
	cur = (unix.tv_sec * 1000000 + unix.tv_usec) / 1000;
	return (cur);
}
