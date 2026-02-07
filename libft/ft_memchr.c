/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbigourd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:27:53 by hbigourd          #+#    #+#             */
/*   Updated: 2022/11/11 17:00:49 by hbigourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *str, int c, size_t n)
{
	char	*strcast;
	size_t	i;

	if (!str && !n)
		return (NULL);
	strcast = (char *) str;
	i = -1;
	while (++i < n)
		if (strcast[i] == (char) c)
			return (&strcast[i]);
	return (NULL);
}
