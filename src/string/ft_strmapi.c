/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:50:40 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:29:46 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who applies the function 'f' to each character of the string 's'
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	i = 0;
	str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}

char	*safe_strmapi(t_libft *libft, const char *s, char (*f)(unsigned int, char))
{
	char	*result;

	if (!libft)
		return (NULL);
	result = ft_strmapi(s, f);
	if (!result)
	{
		SET_ERROR(libft->error_ctx, ERROR_MEMORY, ENOMEM,
			"ft_strmapi() failed for string '%s'", s);
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}
