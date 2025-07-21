/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:38:49 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:02:05 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who locates the first occurrence of the string 'little'
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!big && !len)
		return (NULL);
	if (!*little)
		return ((char *)big);
	while (big[i] && (i + ft_strlen(little)) <= len)
	{
		if (ft_strncmp(big + i, little, ft_strlen(little)) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

char	*safe_strnstr(t_libft *libft, const char *big, const char *little,
		size_t len)
{
	char	*result;

	if (!libft)
		return (NULL);
	result = ft_strnstr(big, little, len);
	if (!result)
	{
		SET_ERROR(libft->error_ctx, ERROR_LOGIC, EINVAL,
			"ft_strnstr() failed for string '%s' and '%s'", big, little);
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}
