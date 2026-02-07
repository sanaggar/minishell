/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 03:56:49 by sannagar          #+#    #+#             */
/*   Updated: 2024/01/18 14:02:40 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	minishell_error(char *input)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(input, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

void	permission_denied(char *input, t_data *data)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(input, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	data->flag_denied_perm = 1;
}

void	error_sentence_exec(char *input, int status, t_data *data)
{
	int	i;

	i = 0;
	if (var_index("PATH=", data) < 0 || (input[i] == '.'
			&& input[i + 1] == '/'))
	{
		if (access(input, F_OK) != 0)
			minishell_error(input);
		else
			permission_denied(input, data);
	}
	else
	{
		if (input)
		{
			data->status = status;
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(input, 2);
			ft_putstr_fd(": command not found\n", 2);
		}
	}
}
