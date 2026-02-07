/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbigourd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:12:22 by hbigourd          #+#    #+#             */
/*   Updated: 2022/11/15 17:26:37 by hbigourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;

	if (nmemb == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	pointer = malloc(nmemb * size);
	if (!pointer)
		return (NULL);
	return (ft_memset(pointer, 0, nmemb * size));
}
