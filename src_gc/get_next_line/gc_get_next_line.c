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
		*line = gc_strjoin_free(ctx, *line, buffer);
		if (!*line)
			return (br);
	}
	return (br);
}

static int	check(int br, char **line)
{
	if (br == -1 || !(*line) || (*line)[0] == '\0')
	{
		free(*line);
		return (0);
	}
	return (1);
}

char	*gc_get_next_line(t_gc_ctx *ctx, int fd)
{
	static char		buffer[1024][BUFFER_SIZE + 1];
	char			*line;
	int				br;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0 || !ctx)
		return (NULL);
	line = NULL;
	if (buffer[fd][0] != '\0')
		line = ft_strjoin_free(NULL, buffer[fd]);
	br = read_file(ctx, fd, &line, buffer[fd]);
	if (!check(br, &line))
		return (NULL);
	if (br <= 0)
		return (line);
	update_line_and_buffer(ctx, &line, buffer[fd]);
	return (line);
}
