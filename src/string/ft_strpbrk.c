/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 23:00:00 by anchikri          #+#    #+#             */
/*   Updated: 2024/07/21 23:00:00 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strpbrk(const char *s, const char *accept)
{
	size_t	i;

	if (!s || !accept)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (ft_strchr(accept, s[i]))
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*safe_strpbrk(t_libft *libft, const char *s, const char *accept)
{
	char		*result;
	t_error_ctx	*error_ctx;

	if (!libft)
	{
		error_ctx = error_ctx_init();
		SET_ERROR(error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"safe_strpbrk: invalid input");
		PRINT_ERROR(error_ctx);
		return (NULL);
	}
	if (!s || !accept)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"safe_strpbrk: invalid input");
		PRINT_ERROR(libft->error_ctx);
		return (NULL);
	}
	result = ft_strpbrk(s, accept);
	return (result);
}
