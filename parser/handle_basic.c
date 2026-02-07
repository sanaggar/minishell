/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:39:08 by sannagar          #+#    #+#             */
/*   Updated: 2024/01/17 04:26:28 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	choose_action(char **inputs, t_data *data)
{
	if (!data->redir)
	{
		data->redir = 1;
		return ;
	}
	if (!ft_strncmp(inputs[0], "echo", ft_strlen("echo")))
		handle_echo(inputs, data);
	else if (!ft_strncmp(inputs[0], "pwd", ft_strlen("pwd")))
		handle_pwd(data);
	else if (!ft_strncmp(inputs[0], "cd", ft_strlen("cd")))
		handle_cd(inputs, data);
	else if (!ft_strncmp(inputs[0], "env", ft_strlen("env")))
		handle_env(inputs, data->env, data);
	else if (!ft_strncmp(inputs[0], "exit", ft_strlen("exit")))
		handle_exit(inputs, data);
	else if (!ft_strncmp(inputs[0], "export", ft_strlen("export")))
		handle_export(inputs, data);
	else if (!ft_strncmp(inputs[0], "unset", ft_strlen("unset")))
		handle_unset(inputs, data);
	else
	{
		handle_exec(inputs, data);
	}
}

void	free_inputs(char **inputs)
{
	int	i;

	i = 0;
	while (inputs[i])
	{
		free(inputs[i]);
		i++;
	}
	free(inputs);
}

void	ft_dup(int *oldfd)
{
	oldfd[0] = dup(1);
	oldfd[1] = dup(0);
}

int	handle_basic(char *clean_input, t_data *data, int piped)
{
	char	**inputs;
	int		oldfd[2];

	if (parser_error(clean_input, data))
	{
		free(clean_input);
		return (0);
	}
	ft_dup(oldfd);
	if (parser_redir(&clean_input, data) == 0)
	{
		clean_input = input_cleaner(clean_input, data);
		dup_close(oldfd, data);
		free(clean_input);
		return (1);
	}
	clean_input = input_cleaner(clean_input, data);
	inputs = input_split(clean_input);
	free(clean_input);
	choose_action(inputs, data);
	free_inputs(inputs);
	dup_close(oldfd, data);
	if (piped)
		exit_pipe(data);
	return (0);
}
