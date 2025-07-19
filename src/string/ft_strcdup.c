/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 02:26:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:25:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who duplicates the string 's' until the character 'c'
char	*ft_strcdup(const char *s, char c)
{
	char	*dup;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	dup = ft_calloc(i + 1, sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, i + 1);
	return (dup);
}

char	*safe_strcdup(t_libft *libft, const char *s, char c)
{
	char	*result;

	if (!libft)
		return (NULL);
	result = ft_strcdup(s, c);
	if (!result)
	{
		SET_ERROR(libft->error_ctx, ERROR_MEMORY, ENOMEM,
			"ft_strcdup() failed for string '%s' with delimiter '%c'", s, c);
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}
