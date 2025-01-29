/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 02:50:23 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 02:50:23 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/garbage.h"

// function who updates the line and the buffer
static void	update_line_and_buffer(t_gc_ctx *ctx, char **line, char *buffer)
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
		tmp = gc_substr(ctx, *line, 0, i);
		if (!tmp)
			return ;
		free(*line);
		*line = tmp;
	}
}

// function who reads the file and updates the line
static int	read_file(t_gc_ctx *ctx, int fd, char **line, char *buffer)
{
	int	br;

	br = 1;
	while (!ft_strchr(buffer, '\n') && br != 0)
	{
		br = read(fd, buffer, BUFFER_SIZE);
		if (br == -1)
		{
			buffer[0] = '\0';
			free(*line);
			*line = NULL;
			return (br);
		}
		buffer[br] = '\0';
		*line = gc_strjoin_gnl(ctx, *line, buffer);
		if (!*line)
			return (br);
	}
	return (br);
}

// function who checks if the line is valid
static int	check(int br, char **line)
{
	if (br == -1 || !(*line) || (*line)[0] == '\0')
	{
		free(*line);
		return (0);
	}
	return (1);
}

// function who reads the file and returns the next line
char	*gc_get_next_line(t_gc_ctx *ctx, int fd)
{
	static char		buffer[1024][BUFFER_SIZE + 1];
	char			*line;
	int				br;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0 || !ctx)
		return (NULL);
	line = NULL;
	if (buffer[fd][0] != '\0')
		line = ft_strjoin_gnl(NULL, buffer[fd]);
	br = read_file(ctx, fd, &line, buffer[fd]);
	if (!check(br, &line))
		return (NULL);
	if (br <= 0)
		return (line);
	update_line_and_buffer(ctx, &line, buffer[fd]);
	return (line);
}
