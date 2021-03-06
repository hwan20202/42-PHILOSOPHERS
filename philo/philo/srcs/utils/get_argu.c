/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:47:33 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 15:47:34 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	get_argu(char *argu, int *p)
{
	*p = ft_atoi(argu);
	if (p < 0)
		return (1);
	return (0);
}
