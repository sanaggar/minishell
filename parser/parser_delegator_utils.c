/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_delegator_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:43:44 by sannagar          #+#    #+#             */
/*   Updated: 2024/01/16 20:45:09 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	else_redir_error(char **input, int *i, t_data *data)
{
	if (!redir_error_pipe1(*input, *i) || !redir_error_pipe(*input, *i))
	{
		free(*input);
		data->status = 2;
		return (1);
	}
	return (0);
}

int	else_redir_error2(char **input, int *i, t_data *data)
{
	if (!redir_error_semi1(*input, *i) || !redir_error_semi(*input, *i))
	{
		free(*input);
		data->status = 2;
		return (1);
	}
	return (0);
}
