/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbigourd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:07:41 by hbigourd          #+#    #+#             */
/*   Updated: 2022/11/11 16:58:44 by hbigourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void const *src, size_t size)
{
	char		*dst;
	const char	*source;

	if (!dest && !src)
		return (NULL);
	source = (char *) src;
	dst = (char *) dest;
	while (size-- > 0)
		*(dst++) = *(source++);
	return (dest);
}
