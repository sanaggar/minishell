/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbigourd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:36:03 by hbigourd          #+#    #+#             */
/*   Updated: 2022/11/15 18:09:47 by hbigourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char const *str)
{
	unsigned int	res;
	int				neg;

	res = 0;
	neg = 1;
	while ((*str > 8 && *str < 14) || *str == ' ')
		str++;
	if ((*str) == '+' || (*str) == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str && ((*str >= '0' && *str <= '9')))
	{
		res += (*str - '0');
		str++;
		if (*str >= '0' && *str <= '9')
			res *= 10;
	}
	return (res * neg);
}
