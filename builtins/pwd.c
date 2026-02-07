/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:37:30 by sannagar          #+#    #+#             */
/*   Updated: 2024/01/18 01:13:59 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_pwd(t_data *data)
{
	char	*current_dir;

	current_dir = getcwd(NULL, 0);
	if (!current_dir)
	{
		error_sentence("pwd: error retrieving current directory: getcwd: \
cannot access parent directories: No such file or directory\n", 1, data);
		free(current_dir);
		data->status = 1;
		return ;
	}
	ft_putstr_fd(current_dir, 1);
	ft_putstr_fd("\n", 1);
	free(current_dir);
	data->status = 0;
}
