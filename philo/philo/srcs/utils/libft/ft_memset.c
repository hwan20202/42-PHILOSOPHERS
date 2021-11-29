/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeokim <jeokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:47:15 by jeokim            #+#    #+#             */
/*   Updated: 2021/11/26 15:47:16 by jeokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memset(void *src, int value, size_t num)
{
	size_t	i;

	i = -1;
	while (++i < num)
	{
		((unsigned char *)src)[i] = (unsigned char)value;
	}
	return (src);
}
