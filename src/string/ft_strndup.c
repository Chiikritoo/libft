/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 02:23:12 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:29:59 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who duplicates the first 'n' characters of the string 's'
char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;

	if (!s)
		return (NULL);
	dup = ft_calloc(n + 1, sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, n + 1);
	return (dup);
}

char	*safe_strndup(t_libft *libft, const char *s, size_t n)
{
	char	*result;

	if (!libft)
		return (NULL);
	result = ft_strndup(s, n);
	if (!result)
	{
		SET_ERROR(libft->error_ctx, ERROR_MEMORY, ENOMEM,
			"ft_strndup() failed for string '%s' with length '%zu'", s, n);
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}
