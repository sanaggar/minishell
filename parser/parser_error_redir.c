/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error_redir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:40:39 by sannagar          #+#    #+#             */
/*   Updated: 2024/01/16 20:30:52 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	redir_error1(char *str, int i)
{
	if (str[i + 2] == '>' && str[i + 3] == '>' )
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `>>'", 2);
		return (0);
	}
	else if (str[i + 2] == '>' && str[i + 3] == '<' )
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `><'", 2);
		return (0);
	}
	else if (str[i + 2] == '<' && str[i + 3] == '<' )
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `<<'", 2);
		return (0);
	}
	else if (str[i + 2] == '<' && str[i + 3] == '>' )
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `<>'", 2);
		return (0);
	}
	return (1);
}

int	redir_error2(char *str, int i)
{
	if (str[i + 2] == '>')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `>'", 2);
		return (0);
	}
	else if (str[i + 2] == '<')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `<'", 2);
		return (0);
	}
	return (1);
}

int	redir_error3(char *str, int i)
{
	if (str[i + 2] == '>' && str[i + 3] == '>' )
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `>>'", 2);
		return (0);
	}
	else if (str[i + 2] == '>' && str[i + 3] == '<' )
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `><'", 2);
		return (0);
	}
	else if (str[i + 2] == '<' && str[i + 3] == '<' )
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `<<'", 2);
		return (0);
	}
	else if (str[i + 2] == '<' && str[i + 3] == '>' )
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `<>'", 2);
		return (0);
	}
	return (1);
}

int	redir_error4(char *str, int i)
{
	if (str[i + 2] == '>')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `>'", 2);
		return (0);
	}
	else if (str[i + 2] == '<')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `<'", 2);
		return (0);
	}
	else if (str[i + 2] == ';' && str[i + 3] == ';' )
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `;;'", 2);
		return (0);
	}
	else if (str[i + 2] == '|' && str[i + 3] == '|' )
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `||'", 2);
		return (0);
	}
	return (1);
}

int	redir_error(char *str, int i)
{
	while (str[i] && str[i] != '>' && str[i] != '<')
		i++;
	if (str[i] && str[i + 1] && str[i] == '>' && str[i + 1] == '>')
	{
		if (!redir_error1(str, i) || !redir_error2(str, i))
			return (0);
	}
	else if (str[i] && str[i + 1] && str[i] == '<' && str[i + 1] == '<')
	{
		if (!redir_error3(str, i) || !redir_error4(str, i))
			return (0);
	}
	else if (str[i] == '>')
	{
		if (!redir_error5(str, i))
			return (0);
	}
	if (str[i] && !redir_error_space(str, i))
		return (0);
	return (1);
}
