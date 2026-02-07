/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbigourd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:25:29 by hbigourd          #+#    #+#             */
/*   Updated: 2022/11/11 15:33:50 by hbigourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *str, int searchedChar)
{
	int	i;

	i = ft_strlen(str) + 1;
	while (--i >= 0)
		if (str[i] == (char) searchedChar)
			return ((char *)str + i);
	return (NULL);
}
