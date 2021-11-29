/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:46:43 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 15:46:44 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "structures.h"
# include <pthread.h>

t_rule				*get_rule(int argc, char **argv);
int					cur_time_update(t_philo *philo);

int					philo_manage(t_rule *rule, t_l *l);

pthread_mutex_t		*malloc_fork(unsigned int size);
pthread_t			*malloc_pthread_t(unsigned int size);

void				*philo_life(void *philo);
unsigned long long	get_cur_time(void);

int					list_iterate_philo_create(t_list *phi_l, t_list *mut_l,
						t_list *mut_l_print);
int					list_iterate_philo_set(t_list *phi_l, t_list *mut_l,
						t_rule *rule);
void				philo_monitor(t_list *phi_l, t_list *mut_l_print);

int					try_eat(t_philo *philo);
int					eating(t_philo *philo);
int					sleeping(t_philo *philo);

#endif