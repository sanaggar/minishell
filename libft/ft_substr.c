/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbigourd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:01:50 by hbigourd          #+#    #+#             */
/*   Updated: 2022/11/16 16:48:25 by hbigourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[i] = '\0';
		return (str);
	}
	if (len < ft_strlen(s))
		str = malloc(sizeof(char) * (len + 1));
	else
		str = malloc (sizeof(char) * (ft_strlen(s) - start + 1));
	if (!str)
		return (NULL);
	start --;
	while (s[++start] && i < len)
		str[i++] = s[start];
	str[i] = '\0';
	return (str);
}
