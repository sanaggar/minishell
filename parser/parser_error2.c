/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 01:24:18 by sannagar          #+#    #+#             */
/*   Updated: 2024/01/17 01:43:06 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	if_semi(char *str)
{
	if (str[0] == ';')
	{
		if (str[1] && str[1] == ';')
			ft_putendl_fd("minishell: syntax error near unexpected token `;;'",
				2);
		else
			ft_putendl_fd("minishell: syntax error near unexpected token `;'",
				2);
		return (1);
	}
	return (0);
}

void	else_error_redir(t_data *data)
{
	if (!ambiguous_error(data->current_input, data))
		return ;
	data->status = 2;
	ft_putstr_fd("Error: wrong or unsupported redirection\n", 2);
}
