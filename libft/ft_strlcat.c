/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbigourd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:57:21 by hbigourd          #+#    #+#             */
/*   Updated: 2022/11/15 20:05:26 by hbigourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t n)
{
	size_t	i;
	size_t	dest_len;

	if ((!dest || !src) && !n)
		return (n);
	if (ft_strlen(dest) >= n)
		return (ft_strlen(src) + n);
	dest_len = ft_strlen(dest);
	i = dest_len - 1;
	while (++i < (n - 1) && src[i - dest_len])
		dest[i] = src[i - dest_len];
	dest[i] = '\0';
	if (n > dest_len)
		return (ft_strlen(src) + dest_len);
	else
		return (ft_strlen(src) + n);
}
