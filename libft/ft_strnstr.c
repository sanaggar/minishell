/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbigourd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:35:47 by hbigourd          #+#    #+#             */
/*   Updated: 2022/11/15 18:48:00 by hbigourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *priSTR, char const *subSTR, size_t len)
{
	size_t	i;

	i = 0;
	if (!*subSTR)
		return ((char *)priSTR);
	while (i < len && priSTR[i])
	{
		if (!ft_strncmp((char *) &priSTR[i], subSTR, ft_strlen(subSTR)))
		{
			if (i + ft_strlen(subSTR) > len)
				return (NULL);
			return ((char *) &priSTR[i]);
		}
		i ++;
	}
	return (NULL);
}
