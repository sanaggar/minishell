/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:38:00 by sannagar          #+#    #+#             */
/*   Updated: 2024/01/18 14:11:32 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	execute_2(char **inputs, t_data *data)
{
	int			i;
	char		**paths;
	int			index;
	struct stat	statounet;

	i = 0;
	statounet.st_mode = 0;
	index = var_index("PATH=", data);
	paths = gen_paths(index, data, inputs[0]);
	while (paths[i])
	{
		stat(paths[i], &statounet);
		if ((statounet.st_mode & S_IXUSR)
			&& (execve(paths[i], inputs, data->env) != -1))
			return (0);
		i++;
	}
	free_env(paths);
	return (1);
}

int	execute(char **inputs, t_data *data)
{
	int			index;
	struct stat	statounet;

	sig_exec_init(data);
	signal(SIGQUIT, SIG_DFL);
	statounet.st_mode = 0;
	index = var_index("PATH=", data);
	stat(inputs[0], &statounet);
	if (ft_strchr(inputs[0], '/') && (statounet.st_mode & S_IXUSR)
		&& (execve(inputs[0], &inputs[0], data->env) != -1))
		return (0);
	else if (index >= 0)
	{
		if (!execute_2(inputs, data))
			return (0);
	}
	if (inputs[0][0] == '\0')
		return (0);
	error_sentence_exec(inputs[0], 127, data);
	if (data->flag_denied_perm == 1)
		return (126);
	else
		return (127);
}

void	handle_exec(char **inputs, t_data *data)
{
	pid_t	pid;
	int		status;

	status = 0;
	sig_exec_init(data);
	pid = fork();
	if (pid == 0)
		exit(execute(inputs, data));
	else if (pid < 0)
		exit(EXIT_FAILURE);
	else
	{
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status))
		{
			data->status = WTERMSIG(status) + 128;
			if (WTERMSIG(status) == 2)
				write(1, "\n", 1);
			if (WTERMSIG(status) == 3)
				printf("Exit (core dumped)\n");
		}
		else
			data->status = WEXITSTATUS(status);
	}
}
