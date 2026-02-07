/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:43:52 by sannagar          #+#    #+#             */
/*   Updated: 2024/01/16 17:43:52 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	*get_next_line(int fd)
{
	static char	memory[NB_FILE_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			read_status;

	if (fd < 0 || fd >= NB_FILE_MAX)
		return (NULL);
	line = ft_strdup_custom(memory[fd]);
	read_status = 1;
	while (ft_strchr_custom(line, '\n') == -1)
	{
		read_status = ft_read(&line, fd);
		if (read_status == 0)
			break ;
		else if (read_status == -1)
			return (NULL);
	}
	if (read_status)
		ft_strlcpy_custom(memory[fd], line
			+ ft_strchr_custom(line, '\n') + 1, BUFFER_SIZE + 1);
	else
		memory[fd][0] = '\0';
	return (line);
}

int	ft_read(char **line, int fd)
{
	char	*tmp;
	int		nb_octet;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
	{
		free(*line);
		return (0);
	}
	nb_octet = read(fd, tmp, BUFFER_SIZE);
	if (nb_octet <= 0)
	{
		free(tmp);
		if (nb_octet == -1)
			free(*line);
		return (0);
	}
	tmp[nb_octet] = '\0';
	*line = ft_strjoin_custom(*line, tmp);
	if (!*line)
	{
		free(tmp);
		return (0);
	}
	return (1);
}
