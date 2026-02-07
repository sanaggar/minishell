/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:50:40 by hbigourd          #+#    #+#             */
/*   Updated: 2023/11/29 23:12:23 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void const *src, size_t size)
{
	char		*dst;
	const char	*source;

	if (!dest && !src)
		return (NULL);
	dst = (char *) dest;
	source = (char const *) src;
	if (source < dst)
	{
		source += (size - 1);
		dst += (size - 1);
		while (size-- > 0)
			*dst-- = *source--;
	}
	else
		while (size-- > 0)
			*dst++ = *source++;
	return (dest);
}
