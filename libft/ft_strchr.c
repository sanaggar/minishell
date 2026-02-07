/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:01:29 by hbigourd          #+#    #+#             */
/*   Updated: 2024/01/17 19:24:08 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *str, int searchedChar)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(str))
	{
		if ((unsigned char)str[i] == (unsigned char)searchedChar)
			return ((char *)&str[i]);
		i++;
	}
	if (searchedChar == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
