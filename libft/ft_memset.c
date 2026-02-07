/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbigourd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:57:00 by hbigourd          #+#    #+#             */
/*   Updated: 2022/11/11 16:56:23 by hbigourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	char	*str;

	if (!pointer && !count)
		return (NULL);
	str = (char *) pointer;
	count += 1;
	while (--count)
		*str++ = value;
	return (pointer);
}
