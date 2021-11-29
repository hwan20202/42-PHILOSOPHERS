/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:46:46 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 16:59:22 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include <stdbool.h>
# include <pthread.h>

# define EPSILON 300
# define ERROR 1

typedef struct s_node
{
	void					*prev;
	void					*content;
	void					*next;
}							t_node;

typedef struct s_list
{
	t_node					*head;
	int						size;
}							t_list;

struct						s_string
{
	char					**s;
	void					*back;
};

struct						s_string_stack
{
	int						size;
	struct s_string			*head;
};

struct						s_rule
{
	int						number_of_philo;
	int						time_to_eat;
	int						time_to_die;
	int						time_to_sleep;
	int						count_to_must_eat;
	struct s_string_stack	*error_message;
};

struct							s_philo
{
	int							own_num;
	pthread_mutex_t				*fir;
	pthread_mutex_t				*sec;
	pthread_mutex_t				*print_lock;
	unsigned long long			start;
	unsigned long long			cur;
	unsigned long long			latest;
	struct s_rule				*rule;
	unsigned long				eating_time;
};

typedef struct s_rule			t_rule;
typedef struct s_philo			t_philo;
typedef struct s_string			t_string;
typedef struct s_string_stack	t_string_stack;
typedef struct s_l
{
	t_list						*pth_l;
	t_list						*mut_l;
	t_list						*phi_l;
	t_list						*mut_l_print;
}								t_l;

#endif