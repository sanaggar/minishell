/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_variable2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 02:33:11 by sannagar          #+#    #+#             */
/*   Updated: 2024/01/17 02:52:27 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_variable(t_data *data, char *tmp, char **input_ad)
{
	free(tmp);
	free(data->var_value);
	free(*input_ad);
}

void	ft_var_value(t_data *data)
{
	if (!data->var_value)
		data->var_value = ft_strdup("");
}
