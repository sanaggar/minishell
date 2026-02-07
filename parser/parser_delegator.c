/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_delegator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:41:33 by sannagar          #+#    #+#             */
/*   Updated: 2024/01/17 19:57:29 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_and_status(t_data *data, char *input, char *new_input)
{
	free(new_input);
	free(input);
	data->status = 2;
}

static int	parser_pipe(char *input, int pipe_pos, t_data *data)
{
	char	*new_input;
	int		space;
	int		i;

	i = -1;
	space = 0;
	if (input[pipe_pos - 1] == ' ')
		space = 1;
	new_input = ft_strdup(&input[pipe_pos + 1]);
	while (input[++i] != '\0')
	{
		if (input[i] == '<' && input[i + 1] == '<')
		{
			free_and_status(data, input, new_input);
			return (ft_putendl_fd("minishell:Unsupported redirection", 2), 0);
		}
	}
	if (input[i - 1] == '|')
	{
		free_and_status(data, input, new_input);
		ft_putendl_fd("minishell: syntax error near unexpected token `|'", 2);
		return (0);
	}
	input[pipe_pos - space] = '\0';
	return (handle_pipe(input, new_input, data));
}

static int	parser_semi(char *input, int semi_pos, t_data *data)
{
	char	*new_input;
	int		space;
	int		i;
	int		flag_pipe;

	i = 0;
	flag_pipe = 0;
	space = 0;
	if (input[semi_pos - 1] == ' ')
		space = 1;
	new_input = ft_strdup(&input[semi_pos + 1]);
	input[semi_pos - space] = '\0';
	while (new_input[i])
	{
		if (new_input[i++] == '|')
			flag_pipe = 1;
	}
	if (!flag_pipe)
		handle_basic(input, data, 0);
	if (data->status != 130)
		return (parser_start(new_input, data));
	else
		free(new_input);
	return (0);
}

int	check_special(char **input, int *i, t_data *data)
{
	if ((*input)[*i] == '\'')
	{
		(*i)++;
		while ((*input)[*i] != '\'')
			(*i)++;
	}
	else if ((*input)[*i] == '|')
	{
		if (else_redir_error(input, i, data))
			return (1);
		parser_pipe((*input), *i, data);
		return (1);
	}
	else if ((*input)[*i] == ';')
	{
		if (else_redir_error2(input, i, data))
			return (1);
		parser_semi((*input), *i, data);
		return (1);
	}
	else if ((*input)[*i] == '$')
		parser_variable(input, i, data);
	(*i)++;
	return (0);
}

int	parser_delegator(char *input, t_data *data, int piped)
{
	int		i;
	int		slash_count;

	i = 0;
	while (input[i])
	{
		if (input[i] == '"')
		{
			i++;
			while (input[i] != '"')
			{
				slash_count = 0;
				while (input[i] == '\\' && ++i)
					slash_count++;
				if (input[i] == '$' && !(slash_count % 2))
					parser_variable(&input, &i, data);
				if (slash_count && !(slash_count % 2))
					i--;
				i++;
			}
		}
		if (check_special(&input, &i, data))
			return (0);
	}
	return (handle_basic(input, data, piped));
}
