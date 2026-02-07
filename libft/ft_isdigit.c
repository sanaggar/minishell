/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:56:24 by hbigourd          #+#    #+#             */
/*   Updated: 2024/01/09 16:08:57 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_too_large_while(char *str, int is_negative, char *min, char *max)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_negative)
		{
			if (str[i] > min[i])
				return (1);
		}
		else
		{
			if (str[i] > max[i])
				return (1);
		}
		i++;
	}
	return (0);
}

int	is_number_too_large(char *str)
{
	char	*max_long_long;
	char	*min_long_long;
	int		is_negative;
	int		str_len;

	is_negative = 0;
	str_len = ft_strlen(str);
	min_long_long = "9223372036854775808";
	max_long_long = "9223372036854775807";
	if (str[0] == '-')
	{
		is_negative = 1;
		str++;
		str_len--;
	}
	if (str_len < 19)
		return (0);
	if (str_len > 19)
		return (1);
	if (is_too_large_while(str, is_negative, min_long_long, max_long_long)
		== 1)
		return (1);
	return (0);
}
