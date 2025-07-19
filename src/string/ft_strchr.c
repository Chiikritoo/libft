/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:41:37 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:26:03 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who locates the first occurrence of 'c' in the string 's'
char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *) &s[i]);
	return (NULL);
}

char	*safe_strchr(t_libft *libft, const char *s, int c)
{
	char	*result;

	if (!libft)
		return (NULL);
	result = ft_strchr(s, c);
	if (!result)
	{
		SET_ERROR(libft->error_ctx, ERROR_LOGIC, EINVAL,
			"character '%c' not found in string '%s'", c, s);
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}
