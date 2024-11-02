/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 05:44:43 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/11/02 23:10:15 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

#include "get_next_line.h"

static int	free_reminder(char **rest_string)
{
	free(*rest_string);
	*rest_string = NULL;
	return (0);
}

static int	read_from_file(char **rest_string, int fd)
{
	char	*buffer;
	int		read_chars;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	read_chars = read(fd, buffer, BUFFER_SIZE);
	while (read_chars > 0)
	{
		buffer[read_chars] = '\0';
		*rest_string = ft_strjoin_and_free(*rest_string, buffer);
		if (!*rest_string)
		{
			free(buffer);
			return (0);
		}
		if (ft_strchr(*rest_string, '\n'))
			break ;
		read_chars = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (read_chars < 0)
		return (free_reminder(rest_string));
	return (1);
}

static char	*last_line(char	**rest_string)
{
	char	*line;

	line = ft_strdup(*rest_string);
	free_reminder(rest_string);
	return (line);
}

static char	*extract_line(char **rest_string)
{
	char	*nl_pos;
	char	*line;
	char	*temp;

	nl_pos = ft_strchr(*rest_string, '\n');
	if (!nl_pos)
		return (last_line(rest_string));
	*nl_pos = '\0';
	line = ft_strdup(*rest_string);
	if (!line)
	{
		free_reminder(rest_string);
		return (NULL);
	}
	line = ft_strjoin_and_free(line, "\n");
	if (nl_pos[1] == '\0')
		free_reminder(rest_string);
	else
	{
		temp = ft_strdup(nl_pos + 1);
		free(*rest_string);
		*rest_string = temp;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rest_string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!rest_string || !ft_strchr(rest_string, '\n'))
	{
		if (!read_from_file(&rest_string, fd))
			return (NULL);
	}
	if (!rest_string)
		return (NULL);
	return (extract_line(&rest_string));
}
