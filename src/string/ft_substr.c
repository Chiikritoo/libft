/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:14:08 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:31:55 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who allocates and returns a substring from the string 's'
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return ("");
	if (len_s - start < len)
		len = len_s - start;
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

char	*safe_substr(t_libft *libft, const char *s, unsigned int start, size_t len)
{
	char	*result;

	if (!libft)
		return (NULL);
	result = ft_substr(s, start, len);
	if (!result)
	{
		SET_ERROR(libft->error_ctx, ERROR_MEMORY, ENOMEM,
			"ft_substr() failed for string '%s' with start '%u' and length '%zu'", s, start, len);
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}
