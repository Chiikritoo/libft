/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:16:39 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:31:06 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who locates the last occurrence of 'c' in the string 's'
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	while (s[i] != (unsigned char)c)
	{
		if (i == 0)
			return (0);
		i--;
	}
	return ((char *) &s[i]);
}

char	*safe_strrchr(t_libft *libft, const char *s, int c)
{
	char	*result;

	if (!libft)
		return (NULL);
	result = ft_strrchr(s, c);
	if (!result)
	{
		SET_ERROR(libft->error_ctx, ERROR_LOGIC, EINVAL,
			"string is null");
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}
