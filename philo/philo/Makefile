# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 16:18:29 by jeokim            #+#    #+#              #
#    Updated: 2021/11/26 16:21:50 by jeokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
SRC		=	srcs/utils/console.c\
			srcs/utils/libft/ft_atoi.c\
			srcs/utils/libft/ft_memset.c\
			srcs/utils/liblist/node_new.c\
			srcs/utils/liblist/list_new.c\
			srcs/utils/liblist/list_push_back.c\
			srcs/utils/liblist/list_iterator.c\
			srcs/utils/liblist/list_free.c\
			srcs/utils/mutex_assign.c\
			srcs/utils/pthread_assign.c\
			srcs/utils/philo_assign.c\
			srcs/utils/get_argu.c\
			srcs/list_iterate_philo_set.c\
			srcs/list_iterate_philo_create.c\
			srcs/philo_monitor.c\
			srcs/get_cur_time.c\
			srcs/get_rule.c\
			srcs/main.c\
			srcs/philo_life.c\
			srcs/philo_manage.c\

OBJ		=	$(SRC:%.c=%.o)

all	 	:	$(NAME)

%.o		:	%.c
	$(CC) $(FLAGS) -I./includes -c $< -o $@

$(NAME)	:	$(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean	:
	rm -rf $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean	all

.PHONY	: all clean fclean re
