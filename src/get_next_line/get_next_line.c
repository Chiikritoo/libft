/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 04:58:06 by anchikri          #+#    #+#             */
/*   Updated: 2023/11/01 04:58:06 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static void	ft_update_line_and_buffer(char **line, char *buffer)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	len = ft_strlen(*line + i + 1);
	ft_memmove(buffer, *line + i + 1, len);
	buffer[len] = '\0';
	if ((*line)[i] == '\n')
	{
		tmp = ft_substr(*line, 0, i + 1);
		if (!tmp)
			return ;
		free(*line);
		*line = tmp;
	}
}

static void	ft_read(int fd, char **line, char *buffer, int *br)
{
	*br = 1;
	while (!ft_strchr(buffer, '\n') && *br != 0)
	{
		*br = read(fd, buffer, BUFFER_SIZE);
		if (*br == -1)
		{
			buffer[0] = '\0';
			free(*line);
			*line = NULL;
			return ;
		}
		buffer[*br] = '\0';
		*line = ft_strjoin_free(*line, buffer);
		if (!*line)
			return ;
	}
}

static int	ft_check(int br, char **line)
{
	if (br == -1 || !(*line) || (*line)[0] == '\0')
	{
		free(*line);
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char		buffer[1024][BUFFER_SIZE + 1];
	char			*line;
	int				br;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (buffer[fd][0] != '\0')
		line = ft_strjoin_free(NULL, buffer[fd]);
	ft_read(fd, &line, buffer[fd], &br);
	if (!ft_check(br, &line))
		return (NULL);
	if (br <= 0)
		return (line);
	ft_update_line_and_buffer(&line, buffer[fd]);
	return (line);
}
