/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:38:38 by sannagar          #+#    #+#             */
/*   Updated: 2024/01/18 03:07:58 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_env_pwd(t_data *data)
{
	char	*pwd;

	data->pwd = getcwd(NULL, 0);
	if (var_index("PWD", data) >= 0)
	{
		pwd = ft_strjoin("PWD=", data->pwd);
		replace_var(pwd, data, var_index(pwd, data));
		free(pwd);
	}
	else
	{
		pwd = ft_strjoin("PWD=", data->pwd);
		data->env = export_env(data->env, pwd);
		free(pwd);
	}
}

void	change_env_oldpwd(t_data *data)
{
	char	*pwd;
	char	*oldpwd;

	if (var_index("OLDPWD", data) >= 0)
	{
		pwd = ft_strjoin("PWD=", data->pwd);
		oldpwd = ft_strjoin("OLD", pwd);
		replace_var(oldpwd, data, var_index("OLDPWD=", data));
		free(oldpwd);
		free(pwd);
	}
	else
		data->env = export_env(data->env, "OLDPWD");
	free(data->pwd);
}

int	change_pwd(t_data *data, char *input)
{
	char	*pwd;
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd && input && ft_strncmp(".", input, ft_strlen(input)) == 0)
	{
		ft_putstr_fd("Error retrieving current directory\n", 2);
		pwd = data->pwd;
		data->pwd = ft_strjoin(pwd, "/.");
		free(pwd);
	}
	if (cwd)
	{
		change_env_oldpwd(data);
		change_env_pwd(data);
	}
	free(cwd);
	return (1);
}
