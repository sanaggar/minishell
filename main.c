/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:43:37 by sannagar          #+#    #+#             */
/*   Updated: 2024/01/18 03:55:11 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signal;

void	end_of_file(t_data *data, char *user_input)
{
	free_env(data->env);
	free(user_input);
	free(data->pwd);
	ft_putstr_fd("exit\n", 2);
	exit(EXIT_SUCCESS);
}

void	data_init(t_data *data, char **env)
{
	g_signal = 0;
	data->status = 0;
	data->env = dup_env(env);
	if (!data->env)
		exit(EXIT_FAILURE);
	data->pwd = getcwd(NULL, 0);
	data->fd_in = 0;
	data->fd_out = 1;
	data->redir = 1;
	data->parent_pid = getpid();
	data->p = 0;
	data->succes_redir = 0;
	data->current_input = NULL;
	data->i_cleaner = 0;
	data->flag_denied_perm = 0;
}

int	main(int ac, char **av, char **env)
{
	t_data	data;
	char	*user_input;

	(void)ac;
	(void)av;
	data_init(&data, env);
	while (1)
	{
		sig_init_main();
		user_input = readline("minishell> ");
		if (!user_input)
			break ;
		else if (*user_input)
		{
			data.current_input = ft_strdup(user_input);
			add_history(user_input);
			parser_start(user_input, &data);
			free(data.current_input);
		}
		else
			free(user_input);
	}
	printf("exit\n");
	exit(EXIT_SUCCESS);
}
