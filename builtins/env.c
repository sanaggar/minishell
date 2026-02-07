/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:38:10 by sannagar          #+#    #+#             */
/*   Updated: 2024/01/18 14:03:55 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_env(char **env)
{
	int	i;
	int	env_len;

	i = 0;
	env_len = envlen(env);
	while (i < env_len)
		free(env[i++]);
	free(env);
}

int	envlen(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (++i);
}

char	**dup_env(char **env)
{
	char	**data_env;
	int		i;

	i = 0;
	data_env = malloc(sizeof(char *) * envlen(env));
	if (!data_env)
		exit(EXIT_FAILURE);
	while (env[i])
	{
		data_env[i] = ft_strdup(env[i]);
		i++;
	}
	data_env[i] = 0;
	return (data_env);
}

void	handle_env(char **inputs, char **env, t_data *data)
{
	int	i;

	i = 0;
	if (inputs[0] && !inputs[1] && ft_strlen(inputs[0]) == 3)
	{
		while (env[i])
		{
			ft_putstr_fd(env[i], 1);
			ft_putchar_fd('\n', 1);
			i++;
		}
	}
	else
	{
		if (inputs[1])
			error_sentence_exec(inputs[1], 127, data);
		else
			error_sentence_exec(inputs[0], 127, data);
	}
}
