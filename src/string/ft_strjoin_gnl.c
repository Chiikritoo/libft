/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:37:20 by anchikri          #+#    #+#             */
/*   Updated: 2023/10/24 20:37:20 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strjoin_gnl(char *line, char *buff)
{
	char	*full_line;
	int		len_line;
	int		len_buff;

	if (!line)
		line = (char *)ft_calloc(1, sizeof(char));
	if (!line || !buff)
		return (NULL);
	len_line = ft_strlen(line);
	len_buff = ft_strlen(buff);
	full_line = (char *)ft_calloc(len_line + len_buff + 1, sizeof(char));
	if (!full_line)
	{
		free(line);
		return (NULL);
	}
	ft_memmove(full_line, line, len_line);
	ft_memmove(full_line + len_line, buff, len_buff + 1);
	free(line);
	return (full_line);
}
