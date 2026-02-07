/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbigourd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:34:28 by hbigourd          #+#    #+#             */
/*   Updated: 2022/11/15 18:02:12 by hbigourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str, char const *s)
{
	char	*comp_str;

	if (!str || !s)
		return (NULL);
	comp_str = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(s) + 1));
	if (!comp_str)
		return (NULL);
	ft_strlcpy(comp_str, str, ft_strlen(str) + 1);
	ft_strlcat(comp_str, s, ft_strlen(s) + ft_strlen(str) + 1);
	return (comp_str);
}
