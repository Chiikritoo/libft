/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:33:36 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:31:44 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who trims the string 's1' with the characters in 'set'
char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;

	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strrchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}

char	*safe_strtrim(t_libft *libft, const char *s1, const char *set)
{
	char	*result;

	if (!libft)
		return (NULL);
	result = ft_strtrim(s1, set);
	if (!result)
	{
		SET_ERROR(libft->error_ctx, ERROR_MEMORY, ENOMEM,
			"ft_strtrim() failed for string '%s' and '%s'", s1, set);
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}
