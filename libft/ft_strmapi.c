/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbigourd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:27:51 by hbigourd          #+#    #+#             */
/*   Updated: 2022/11/13 21:07:38 by hbigourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (!str)
		return (NULL);
	res = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = f(i, str[i]);
		i ++;
	}
	res[i] = '\0';
	return (res);
}
