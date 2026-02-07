/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:41:49 by sannagar          #+#    #+#             */
/*   Updated: 2024/01/16 17:41:51 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*find_next_input(char *str)
{
	char	quote;
	int		slash_count;

	str--;
	while (*(++str))
	{
		if (*str == '"' || *str == '\'')
		{
			quote = *(str++);
			while (*str != quote)
			{
				slash_count = 0;
				while (*str == '\\' && quote == '"' && ++slash_count)
					str++;
				if (slash_count && !(slash_count % 2))
					str--;
				str++;
			}
		}
		if (*str == ' ')
			return (str + 1);
	}
	return (str);
}

static size_t	stringcount(char *str)
{
	int		i;
	char	quote;
	int		slash_count;

	i = 1;
	str--;
	while (*(++str))
	{
		if (*str == '"' || *str == '\'')
		{
			quote = *(str++);
			while (*str != quote)
			{
				slash_count = 0;
				while (*str == '\\' && quote == '"' && ++slash_count)
					str++;
				if (slash_count && !(slash_count % 2))
					str--;
				str++;
			}
		}
		if (*str == ' ')
			i++;
	}
	return (i);
}

char	*newsplit(char *src)
{
	int		len;
	char	*dst;
	char	quote;

	quote = 0;
	len = ft_strlen(src);
	dst = malloc((len + 1) * sizeof(char));
	if (!dst)
		exit(EXIT_FAILURE);
	copy_newsplit(src, dst, quote);
	return (dst);
}

char	**input_split(char *str)
{
	char	**inputs;
	size_t	count;
	size_t	i;

	count = stringcount(str);
	inputs = malloc((count + 1) * sizeof(char *));
	if (!inputs)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < count)
	{
		inputs[i++] = newsplit(str);
		if (i > 0 && !inputs[i - 1])
			return (NULL);
		str = find_next_input(str);
	}
	inputs[i] = NULL;
	return (inputs);
}
