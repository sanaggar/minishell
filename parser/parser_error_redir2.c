/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error_redir2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:40:53 by sannagar          #+#    #+#             */
/*   Updated: 2024/01/16 19:54:40 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	redir_error5(char *str, int i)
{
	if (str[i + 1] == '<' && str[i + 2] == '<')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `<<'", 2);
		return (0);
	}
	else if (str[i + 1] == '<' && str[i + 2] == '>')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `<>'", 2);
		return (0);
	}
	else if (str[i + 1] == '<')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `<'", 2);
		return (0);
	}
	return (1);
}

int	redir_error_pipe(char *str, int i)
{
	if (str[i + 1] == '|' && str[i - 1] == '<')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `||'", 2);
		return (0);
	}
	else if (str[i + 1] == '|' && str[i - 1] == '>')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `||'", 2);
		return (0);
	}
	else if (str[i - 1] == '<')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `|'", 2);
		return (0);
	}
	else if (str[i - 1] == '>')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `|'", 2);
		return (0);
	}
	return (1);
}

int	redir_error_pipe1(char *str, int i)
{
	if (str[0] == '|')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `|'", 2);
		return (0);
	}
	if (i < 2 || !redir_error(str, i - 2))
		return (0);
	if (str[i + 1] && str[i - 1] && str[i + 1] == ';' && str[i - 1] == '<')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `|;'", 2);
		return (0);
	}
	else if (str[i + 1] && str[i - 1] && str[i + 1] == ';' && str[i - 1] == '>')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `|;'", 2);
		return (0);
	}
	return (1);
}

int	redir_error_semi(char *str, int i)
{
	if (if_semi(str))
		return (0);
	if (str[i + 1] == ';' && str[i - 1] == '<')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `;;'", 2);
		return (0);
	}
	else if (str[i + 1] == ';' && str[i - 1] == '>')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `;;'", 2);
		return (0);
	}
	else if (str[i - 1] == '<')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `;'", 2);
		return (0);
	}
	else if (str[i - 1] == '>')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `;'", 2);
		return (0);
	}
	return (1);
}

int	redir_error_semi1(char *str, int i)
{
	if (i >= 2)
	{
		if (!redir_error(str, i - 2))
			return (0);
	}
	else
	{
		if (!redir_error(str, i))
			return (0);
	}
	if (str[i + 1] == '|' && str[i - 1] == '<')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `;|'", 2);
		return (0);
	}
	else if (str[i + 1] == '|' && str[i - 1] == '>')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `;|'", 2);
		return (0);
	}
	return (1);
}
