/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_f2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:42:08 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:27:20 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who concatenates the strings 's1' and 's2' and frees 's2'
char	*ft_strjoin_f2(const char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*s3;

	if (!s2)
		return (NULL);
	if (!s1)
		return (free(s2), NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!s3)
		return (free(s2), NULL);
	ft_strlcpy(s3, s1, len_s1 + 1);
	ft_strlcat(s3, s2, len_s1 + len_s2 + 1);
	free(s2);
	return (s3);
}

char	*safe_strjoin_f2(t_libft *libft, const char *s1, char *s2)
{
	char	*result;

	if (!libft)
		return (NULL);
	result = ft_strjoin_f2(s1, s2);
	if (!result)
	{
		SET_ERROR(libft->error_ctx, ERROR_MEMORY, ENOMEM,
			"ft_strjoin_f2() failed for string '%s' and '%s'", s1, s2);
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}
