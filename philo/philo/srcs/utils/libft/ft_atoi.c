/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:47:13 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 15:47:14 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_isspace(char c)
{
	if (c == '\n'
		|| c == '\v'
		|| c == '\t'
		|| c == '\r'
		|| c == '\f'
		|| c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	char	*tmp;
	int		i;
	int		result;
	int		flag;

	i = 0;
	flag = 1;
	result = 0;
	tmp = (char *)str;
	while (ft_isspace(tmp[i]))
		++i;
	if (tmp[i] == 43 || tmp[i] == 45)
	{
		if (tmp[i] == 45)
			flag = -1;
		++i;
	}
	while (tmp[i] != 0 && (tmp[i] >= '0' && tmp[i] <= '9'))
	{
		result = result * 10;
		result = result + (tmp[i] - '0');
		++i;
	}
	return (flag * result);
}
