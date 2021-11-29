/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:46:48 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 16:00:15 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <pthread.h>
# include "structures.h"

int		console(char *s, int return_value);
void	message(t_philo *philo, char *s1, char *s2);
void	dieing_message(t_list *mut_l_print, t_philo *philo);
int		ft_atoi(const char *str);
void	*ft_memset(void *src, int value, size_t num);
int		get_argu(char *argu, int *p);

int		pthread_assign(void *p);
int		mutex_assign(void *p);
int		philo_assign(void *p);

t_list	*list_new(void);
t_node	*node_new(void);
int		list_push_back(t_list *list, t_node *node);
int		list_iterator(t_list *list, int (*fp)(void *));
void	list_free(t_list	*list);
int		content_free(void *node);

#endif