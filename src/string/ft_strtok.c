/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:10:00 by anchikri          #+#    #+#             */
/*   Updated: 2024/07/21 22:10:00 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Thread-safe strtok: nextp doit pointer sur un char* initialisé à NULL au premier appel
char	*ft_strtok(char *str, const char *delim, char **nextp)
{
	char	*start;

	if (!str && nextp && *nextp)
		str = *nextp;
	if (!str || !delim)
		return (NULL);
	// Skip leading delimiters
	while (*str && ft_strchr(delim, *str))
		str++;
	if (!*str)
	{
		if (nextp)
			*nextp = NULL;
		return (NULL);
	}
	start = str;
	while (*str && !ft_strchr(delim, *str))
		str++;
	if (*str)
	{
		*str = '\0';
		str++;
		if (nextp)
			*nextp = str;
	}
	else if (nextp)
		*nextp = NULL;
	return (start);
}

