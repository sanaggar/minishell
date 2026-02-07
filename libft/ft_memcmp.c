/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbigourd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:51:34 by hbigourd          #+#    #+#             */
/*   Updated: 2022/11/15 20:47:14 by hbigourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void const *pointer1, void const *pointer2, size_t size)
{
	size_t				i;
	unsigned char const	*p1;
	unsigned char const	*p2;

	if (!pointer1 && !pointer2)
		return (0);
	p1 = (unsigned char *)pointer1;
	p2 = (unsigned char *)pointer2;
	i = 0;
	while (i < size)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i ++;
	}
	return (0);
}
