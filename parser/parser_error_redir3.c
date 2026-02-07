/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error_redir3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:40:46 by sannagar          #+#    #+#             */
/*   Updated: 2024/01/16 17:40:48 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	redir_error_space(char *str, int i)
{
	if (str[i + 1] != '\0' && (str[i + 1] == '<' || str[i + 1] == '>'))
		return (1);
	while (str[i + 1] && str[i + 1] == ' ')
		i++;
	if (str[i + 1] && str[i + 1] == '>')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `>'", 2);
		return (0);
	}
	else if (str[i + 1] && str[i + 1] == '<')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `<'", 2);
		return (0);
	}
	else if (str[i + 1] && str[i + 1] == ';')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `;'", 2);
		return (0);
	}
	else if (str[i + 1] && str[i + 1] == '|')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `|'", 2);
		return (0);
	}
	return (1);
}
