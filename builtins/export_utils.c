/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:37:38 by sannagar          #+#    #+#             */
/*   Updated: 2024/01/18 13:49:59 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	check_export(char *str, t_data *data)
{
	char	**split;

	data->index_i = 0;
	if (str[0] == '\0')
		return (0);
	if (ft_isdigit(str[data->index_i]))
		return (0);
	while (str[data->index_i] && str[data->index_i] != '=')
	{
		if (!ft_isalnum(str[data->index_i]) && str[data->index_i] != '_')
			return (0);
		data->index_i++;
	}
	split = ft_split(data->current_input, '=');
	if (str[data->index_i] == '=')
	{
		data->index = var_index(str, data);
		if (data->index != -1)
		{
			if (ft_strchr(data->env[data->index], '=') != NULL
				&& ft_strchr(split[0], '$') != NULL)
				return (free_split(split), 0);
		}
	}
	return (free_split(split), 1);
}

int	print_export(char **env)
{
	int	i;
	int	j;
	int	equal;

	i = -1;
	while (env[++i])
	{
		equal = 1;
		j = 0;
		ft_putstr_fd("declare -x ", 1);
		while (env[i][j])
		{
			if (env[i][j] == '\\' || env[i][j] == '$' ||
			env[i][j] == '\"')
				write(1, "\\", 1);
			write(1, &env[i][j], 1);
			if (env[i][j] == '=' && equal-- == 1)
				write(1, "\"", 1);
			j++;
		}
		if (equal != 1)
			write(1, "\"", 1);
		write(1, "\n", 1);
	}
	return (1);
}

void	sentence_handle_export(t_data *data, char **inputs, int i)
{
	ft_putstr_fd("minishell: export: '", 1);
	ft_putstr_fd(inputs[i], 1);
	error_sentence("': not a valid identifier\n", 1, data);
	data->status = 1;
}

void	export_env_handle_env(t_data *data, char **inputs, int i)
{
	data->env = export_env(data->env, inputs[i]);
	if (!data->env)
		exit(EXIT_FAILURE);
}
