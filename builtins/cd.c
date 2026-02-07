/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:36:52 by sannagar          #+#    #+#             */
/*   Updated: 2024/01/18 03:08:16 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cd_minus(t_data *data)
{
	if (var_index("OLDPWD=", data) < 0
		|| chdir((strchr(data->env[var_index("OLDPWD=", data)], '=')
				+ 1)) == -1)
		return (0);
	change_pwd(data, NULL);
	return (1);
}

int	cd_alone(t_data *data)
{
	if (var_index("HOME=", data) < 0
		|| data->env[var_index("HOME=", data)][5] == '\0')
		return (1);
	if (chdir((strchr(data->env[var_index("HOME=", data)], '=') + 1)) == -1)
		return (0);
	change_pwd(data, NULL);
	return (1);
}

int	cd_path(char **args, t_data *data)
{
	if (chdir(args[1]) == -1)
		return (0);
	change_pwd(data, args[1]);
	return (1);
}

void	handle_cd(char **args, t_data *data)
{
	char	*current_dir;

	current_dir = getcwd(NULL, 0);
	if (args[1] && args[2])
		return (error_sentence("cd: too many arguments\n", 1, data));
	else if (!args[1])
	{
		if (!cd_alone(data))
			return (error_sentence("cd: HOME: is undefined\n", 1, data));
	}
	else if (ft_strncmp(args[1], "-", ft_strlen("-")) == 0)
	{
		if (!cd_minus(data))
			return (error_sentence("cd: OLDPWD is undefined\n", 1, data));
	}
	else
	{
		if (!cd_path(args, data) || !current_dir)
		{
			free(current_dir);
			return (error_sentence("cd: no such file or directory\n", 1, data));
		}
	}
	free(current_dir);
	data->status = 0;
}
