/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:20:22 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:26:44 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who duplicates the string 's'
char	*ft_strdup(const char *s)
{
	char	*dup;

	if (!s)
		return (NULL);
	dup = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, ft_strlen(s) + 1);
	return (dup);
}

char	*safe_strdup(t_libft *libft, const char *s)
{
	char	*result;

	if (!libft)
		return (NULL);
	result = ft_strdup(s);
	if (!result)
	{
		SET_ERROR(libft->error_ctx, ERROR_MEMORY, ENOMEM,
			"ft_strdup() failed for string '%s'", s);
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}
